function [delay] =control_network_delay_summary(result)

% 1 2 3 4 5 6 7 8 9, in total 9 delivery status
if(~isempty(result))
        result_num = zeros(1, 2);
        result_num = result;
        sz_y=1;
        %[sz_x,sz_y] = size(result_num);
        delay=[0]; % 9 delivery status
        for i_rn = 1:sz_y
            %disp('result')
            %disp(result_num(9+i_rn))
            if result_num(1+i_rn) > 0
                delay(1, i_rn) = result_num(1+i_rn);
            else
                delay(1, i_rn) = delay(1, i_rn);
            end
        end
else
    delay=[0];
end