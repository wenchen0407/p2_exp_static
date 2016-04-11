function [resultz] = ps_aggregation (call_count)

resultz = zeros(1, 6);

for i_pa = 1 : call_count
    %disp('emergency instance');
    %disp(emergency_instance)
    [result status]=python('tossim-event-client-ps.py');
    %disp(result);
    if i_pa == 51
        resultz=str2num(result);
        disp('result: ');
        disp(resultz);
    end
end