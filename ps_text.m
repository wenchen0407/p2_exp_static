function [resultz] = ps_text (call_count)

resultz = zeros(1, 6);

text = fopen('noError.txt');
line_num=1;
result = fgets(text);
while ischar(result)
    if line_num == call_count
        resultz = str2num(result);
        break;
    end
    result = fgets(text);
    line_num = line_num+1;
end
fclose(text);

% for i_pa = 1 : call_count
%     %disp('emergency instance');
%     %disp(emergency_instance)
%     [result status]=python('tossim-event-client-ps.py');
%     %disp(result);
%     if i_pa == 51
%         resultz=str2num(result);
%         disp('result: ');
%         disp(resultz);
%     end
% end