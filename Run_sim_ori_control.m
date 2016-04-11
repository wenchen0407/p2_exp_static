clc;
clear all;
close all;
warning off
%% Uncontrol

sim_inp;  %where the input constants coming

Tf = 10;% 10 is the max time for the El Centro earthquake

sim('simul_uncontrol_EI',[0 Tf])

zzout = abs([zout(:,1) zout(:,2)-zout(:,1) zout(:,3)-zout(:,2) ]);
accout = abs([zout(:,9) zout(:,10) zout(:,11)]);

Mmax(1,:) = max(zzout,[],1);
Amax(1,:)= max(abs(zout(:,9:11)),[],1);

sigma_x3 = std(zout(30000:end,3)) % volt to cm (/0.51)
sigma_v3 = std(zout(30000:end,7)) % 2.04e-2 V*s/cm
sigma_a3 = std(zout(30000:end,11))

d_nc = max(zzout,[],1) % peak interstory drift
acc_nc = max(accout,[],1) % peak acc

save unctrol_output sigma_x3 sigma_v3 sigma_a3 acc_nc d_nc
clear usignal zout;

%% RUN INTEGRATED SIMULATION 
tic

dtint = 10^-3; % sample time for integrated model
step_count=Tf/dtint; 
Ydelay = zeros(step_count+1,4);
Delay = 0;
qint 	= 6/(2^12);	% quantizer interval
ranD = [4 2 2 2]; % delayed time steps 

for k=1%:50
    
    clear ZOUT_in_r usignal TIME
    %delay1 = importdata(['Delay_series_100run_chnl_26_',num2str(k),'.mat']);
    delay1 = zeros(step_count+1,5);
    
    yin = [0 0 0 0];
    yin_d = [0 0 0 0]';
    count = 1;
    i = 0;

    % define input for delayed data (embeded matlab) block 
    structure.i = 0;
    structure.count = count;
    structure.yin = yin;
    structure.yin_d = yin_d;
    structure.delay1 = delay1;
    structure.ranD = ranD;

    option = simset('solver','ode4','FixedStep',dtint);
    sim('SIMUL_step_delay_Embed_integrated_v3.mdl',[0 Tf])
    delay_trace = Ydelay(1:10:end,:); % delay traces 
    % evaluation Criteria
    ZOUT=ZOUT_in_r;U=usignal;
    [J(:,k)]= evaluation(ZOUT,U)
end

save Sim_building_ori_final_02_27_13 J

toc

% figure(1)
% subplot(511);plot(TIME,ZOUT_in_r(:,1),'r')
% ylabel('d1')
% subplot(512);plot(TIME,ZOUT_in_r(:,2)-ZOUT_in_r(:,1),'r')
% ylabel('d2')
% subplot(513);plot(TIME,ZOUT_in_r(:,3)-ZOUT_in_r(:,2),'r')
% ylabel('d3')
% subplot(514);plot(TIME,ZOUT_in_r(:,9),'r')
% ylabel('Acc1')
% subplot(515);plot(TIME,ZOUT_in_r(:,11),'r')
% ylabel('Acc3')





