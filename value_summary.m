function [value] =value_summary(result)

% 1 2 3 4 5 6 7 8 9, in total 9 delivery status

if(~isempty(result))
        result_num = zeros(1, 6);
        result_num = result;
        sz_y=3;
        %[sz_x,sz_y] = size(result_num);
        value=[88 88 88]; % 9 delivery status
        for i_rn = 1:sz_y
            if result_num(i_rn) >= 1
                value(1, i_rn) = 1;
            else
                value(1, i_rn) = value(1, i_rn);
            end
        end
else
    value=[88 88 88];
end