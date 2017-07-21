function [pstruc ] = analyse_problemdata( problemdata )
%UNTITLED Summary of this function goes here
%   Detailed explanation goes her

%clear pstruct
%Untersucht welche Eingangsmatrizen äquivalent sind
pnames=fieldnames(problemdata);
pnames=setdiff(pnames,{'xinit','dim'});
pstruct.s=zeros(problemdata.dim.K,size(pnames,1)*2-4);
pstruct.id_diff_input=zeros(problemdata.dim.K+1,size(pnames,1))-1;
for k1=1:size(pnames,1)
    
    %pnames{k1}
    tempfield=getfield(problemdata,pnames{k1});
    N2=size(tempfield,1);
    if iscell(tempfield)
        maxM2=size(tempfield{1},1)*size(tempfield{1},2);
        for k2=1:size(tempfield,1)
            pstruct.s(k2,(k1*2-1):(k1*2))=[size(tempfield{k2},1),size(tempfield{k2},2)];
        end
        maxM2=max(pstruct.s(:,2*k1-1).*pstruct.s(:,2*k1));
        pstruct.v{k1}=zeros(N2,maxM2+3);
        eqcount=1;
        veq=[];
        for k2=1:size(tempfield,1)
            
            eqfound=0;
            k3=1;
            M2a=pstruct.s(k2,k1*2-1);
            M2b=pstruct.s(k2,k1*2);
            M2=M2a*M2b;
            while (k3<=(eqcount-1))&&(eqfound==0)
                
                j3=find(pstruct.v{k1}(:,1)==k3, 1,'first');
                
                if isempty(tempfield{k2})
                    eqfound=-1;
                elseif (M2a==pstruct.v{k1}(j3,2))&&(M2b==pstruct.v{k1}(j3,3))&&(all(reshape(tempfield{k2},1,M2)==pstruct.v{k1}(j3,4:(3+M2))))
                    eqfound=j3;
                end
                
                k3=k3+1;
            end
            
            if eqfound~=1
                pstruct.v{k1}(k2,1:(3+M2))=[eqcount,pstruct.s(k2,2*k1-1),pstruct.s(k2,2*k1),reshape(tempfield{k2},1,M2)];
                pstruct.m1{k1}(eqcount,1:M2)=(reshape(tempfield{k2},1,M2)~=0)+0;
                maxM2=max(pstruct.s(:,2*k1-1).*pstruct.s(:,2*k1));
                pstruct.m1{k1}(eqcount,(M2+1):maxM2)=-1;
                pstruct.s1{k1}(eqcount,1)=pstruct.s(k2,2*k1-1);
                pstruct.s1{k1}(eqcount,2)=pstruct.s(k2,2*k1);
                pstruct.index_diff_input(k2,k1)=eqcount;
                pstruct.id_diff_input(eqcount,k1)=k2;
                eqcount=eqcount+1;
                if k1==6
                    
                end
                
            else
                pstruct.v{k1}(k2,1:3)=[pstruct.v{k1}(eqfound,1),pstruct.s(k2,2*k1-1),pstruct.s(k2,2*k1)];
                pstruct.index_diff_input(k2,k1)=eqfound;
            end
            
            
        end
        %pstruct.v{k1}(:,1:3)
    end
end

j1=1;
for k1=1:size(pnames,1)
    
    if ~isempty(pstruct.v{k1})%&&~((max(pstruct.v{k1}(:,1)))==(size(pstruct.v{k1},1)))
        
        pstruc.names{j1}=pnames{k1};
        pstruc2.v{j1}=pstruct.v{k1}(:,1:3);
        pstruc2.m1{j1}=pstruct.m1{k1};
        pstruc2.s1{j1}=pstruct.s1{k1};
        pstruc.N_diff_input(j1)=max(pstruct.v{k1}(:,1));
        pstruc.id_diff_input(:,j1)=pstruct.id_diff_input(:,k1);
        pstruc.index_diff_input(:,j1)=pstruct.index_diff_input(:,k1);
        j1=j1+1;
    end
    
end

%pstruc.dim1=pstruct.s(:,5:2:end);
%pstruc.dim2=pstruct.s(:,6:2:end);

% Finde alle Einträge mit selber Struktur
pstruc.N_diff_struct=pstruc.N_diff_input*0;
pstruc.index_diff_struct=[];
pstruc.Kindex_diff_struct=[];
pstruc.id_diff_struct=zeros(max(pstruc.N_diff_input),length(pstruc.N_diff_input))-1;
for i1=1:length(pstruc.N_diff_input)
    temp=pstruc2.m1{i1};
    
    for i2=1:pstruc.N_diff_input(i1)
        
        isfound=0;
        i3=0;
        
        while (i3<pstruc.N_diff_struct(i1))&&(isfound==0)
            i3=i3+1;
            isfound=all(temp(i3,:)==temp(i2,:));
        end
        if isfound==0
            pstruc.N_diff_struct(i1)=pstruc.N_diff_struct(i1)+1;
            pstruc.id_diff_struct(i2,i1)=pstruc.N_diff_struct(i1);
            pstruc.index_diff_struct(pstruc.N_diff_struct(i1),i1)=i2;
            pstruc.Kindex_diff_struct(pstruc.N_diff_struct(i1),i1)=pstruc.id_diff_input(i2,i1);
            pstruc.v_diff_struct{i1}{pstruc.N_diff_struct(i1)}=temp(i2,:);
        else
            pstruc.id_diff_struct(i2,i1)=pstruc.index_diff_struct(i3,i1);
        end
    end
    
end
pstruc.N_diff_dim=pstruc.N_diff_input*0;
pstruc.index_diff_dim=[];
pstruc.Kindex_diff_dim=[];
% Finde alle Einträge mit selber Dimension
pstruc.id_diff_dim=zeros(max(pstruc.N_diff_struct),length(pstruc.N_diff_input))-1;
for i1=1:length(pstruc.N_diff_struct)
    temp=pstruc2.s1{i1};
    for i2=1:pstruc.N_diff_struct(i1)
        I=pstruc.index_diff_struct(i2,i1);
        temp2=temp(I,:);
        isfound=0;
        i3=0;
        
        while (i3<pstruc.N_diff_dim(i1))&&(isfound==0)
            i3=i3+1;
            isfound=all(pstruc.v_diff_dim{i1}(i3,:)==temp2);
        end
        if isfound==0
            pstruc.N_diff_dim(i1)=pstruc.N_diff_dim(i1)+1;
            pstruc.id_diff_dim(i2,i1)=pstruc.N_diff_dim(i1);
            pstruc.index_diff_dim(pstruc.N_diff_dim(i1),i1)=i2;
            pstruc.Kindex_diff_dim(pstruc.N_diff_dim(i1),i1)=pstruc.Kindex_diff_struct(i2,i1);
            pstruc.v_diff_dim{i1}(i3+1,:)=temp2;
        else
            pstruc.id_diff_dim(i2,i1)=pstruc.index_diff_dim(i3,i1);
        end
    end
    
end

A=unique(pstruc.Kindex_diff_struct);
a=A(A~=0)-1;

if a(1)~=0
    a=[0;pa];
end

a(end+1)=problemdata.dim.K+1;



for i=1:(length(a)-1)
    
    pstruc.it_struct{i}=a(i):(a(i+1)-1);
    
end

A=unique(pstruc.Kindex_diff_dim);
a=A(A~=0)-1;

if a(1)~=0
    a=[0;pa];
end



a(end+1)=problemdata.dim.K+1;



for i=1:(length(a)-1)
    
    pstruc.it_dim{i}=a(i):(a(i+1)-1);
    
end

end
