function [kp,kstr] = additer(k,i1,type)
global gendata
global aiter

aiter.open_bracket=0;
aiter.id_iter=i1;
aiter.stat_mult=1;
if (nargin>2)&&(type==1)
    
    if gendata.mem_type==2
        v=gendata.iter{i1};
        if length(v)==1
            kp=v(1);
            kstr = num2str(kp);
        else
            addl(['  for(i1=',num2str(v(end)),'; i1>', num2str(v(1)-1), '; i1--){']);
            kp=v(end);
            kstr=num2str(kp);
            aiter.kstr='i1';
            aiter.k=kp;
            aiter.open_bracket=1;
            aiter.stat_mult=v(end)-v(1)+1; % Function statistic count multiplied by stat_mult
            
        end
    else
        kp=k;
        kstr = num2str(k);
    end
    
else
    
    if gendata.mem_type==2
        v=gendata.iter{i1};
        if length(v)==1            kp=v(1);
            kstr = num2str(kp);
        else
            addl(['  for(i1=',num2str(v(1)),'; i1<', num2str(v(end)+1), '; i1++){']);
            kp=v(1);
            kstr=num2str(kp);
            aiter.kstr='i1';
            aiter.k=kp;
            aiter.open_bracket=1;
            aiter.stat_mult=v(end)-v(1)+1; % Function statistic count multiplied by stat_mult
        end
    else
        kp=k;
        kstr = num2str(k);
    end
    
end

end

