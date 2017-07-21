function [ ] = analyse_savestruct( )
% ANALYSE_SAVESTRUCT Analyses input data structure and saves information in global variable
% genstore.iter.types_arr(zid,zd,start_info,end_info) 
% zid - Structure type
% zid==1, varying dimension during iteration interval, zid==2
% same dimension, zid==3 same element
% zd - Distance between consecutive entries
% start_info - Can element of index -1, be addressed in same fashion
% end_info-Can element of index +1 be adressed in same fashion

global genstore
global gendata
for k1=1:length(gendata.iter)
    N1=length(genstore.v_arr); %Achtung, wenn merhere Datentypen Überarbeitung
    I2=gendata.iter{k1}+1;
    N2=length(I2);
    v=zeros(N2,N1);
    if N2>1
        for i1=1:length(genstore.v_arr)
            
            v(:,i1)=genstore.v_arr{i1}(I2,3);
            z=unique(diff(v(:,i1)));
            zid=1;
            % Array starting index, has same distance
            if(length(z))==1
                zid=2;
                zd=z;
                genstore.iter{k1}.types_arr(2,i1)=zd;
                %Distance is zero, same entry
                if zd==0
                    zid=3;
                end
            end
            genstore.iter{k1}.types_arr(1,i1)=zid;
            genstore.iter{k1}.types_arr(3,i1)=0;
            genstore.iter{k1}.types_arr(4,i1)=0;
            if zid~=1
                d1=diff(genstore.v_arr{i1}((I2(1)-1):I2(1),3));
                d2=diff(genstore.v_arr{i1}((I2(end)):(I2(end)+1),3));
                if (zid==3)&&(d1==0)
                    genstore.iter{k1}.types_arr(3,i1)=1;
                end
                if (zid==3)&&(d2==0)
                    genstore.iter{k1}.types_arr(4,i1)=1;
                end
                if (zid==2)&&(d1==zd)
                    genstore.iter{k1}.types_arr(3,i1)=1;
                end
                if (zid==2)&&(d2==zd)
                    genstore.iter{k1}.types_arr(4,i1)=1;
                end
                
            end
            
        end
    end
end