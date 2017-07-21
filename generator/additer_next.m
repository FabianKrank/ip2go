function [kp ] = additer_next(k,i1,type)
global gendata
global aiter

if (nargin>2)&&(type==1)
    if gendata.mem_type==2
        v=gendata.iter{i1};
        if aiter.open_bracket==1
            addl('  }');
            aiter.open_bracket=0;
        end
        kp=v(1)-1;
        
    else
        
        kp=k-1;
    end
else
    if gendata.mem_type==2
        v=gendata.iter{i1};
        if aiter.open_bracket==1
            addl('  }');
            aiter.open_bracket=0;
        end
        kp=v(end)+1;
        
    else
        
        kp=k+1;
    end
end



end

