clc;
clear all;
close all;
warning off
%%
% Tf = 200;               % 200s

Tf = 300;              % 1s
sensor_sampling_rate = 10; %sampling rate
EMPeriod = 1;        %step counter in emergency mode

% this one is critical as it controls how much we count as a superframe?
delta_t = 1 / sensor_sampling_rate; %control periodx
step_count = Tf * sensor_sampling_rate; %total step count
sen_num = 3; % sensor number
%dtint = 100*delta_t; %what is this used for?

%% RUN Wireless  Process Control Simulation
tic
%Ydelay = zeros(step_count+1, sen_num);
Delay = 0;
ranD=[4 2 2 2 2]; %delayed time steps 

%last_emergency_instance=[0 0 0 0 0]';
% for k=1 : 15
for k=1 : 1
    clear L1OUT L2OUT TIME BASINOUT DOUT PumOUT
    clear L1OUT1 L2OUT1 BASINOUT1 DOUT1 PumOUT1
    
    %sensor_value = zeros(step_count + 1, sen_num);
    %Ydelay = zeros(step_count + 1, 4);
    yin = [0 0 0];
    ynd_tmp = [0 0 0];
    
    yin_d = [0 0 0]';
    delay_v= [0 0 0]';

    %yin_all = zeros(step_count+1,9); %zeros (step count, sensor number)
    %ynd_all=zeros(step_count+1,9);
    
    %ystore = Ydelay;
    count = 1;
    i = 0;
    
    structure.i = 0;
    structure.count = count;
    structure.sen_num=9;
    structure.yin = yin;
    structure.yin_d = yin_d;
    structure.delay_v = delay_v;
    structure.ynd_tmp = ynd_tmp;
    %structure.sensor_value = sensor_value;
    structure.ranD = ranD;
    
    %structure.yin_all=yin_all;
    %structure.ynd_all=ynd_all;

    %last_emergency_instance=[0 0 0 0 0];
    %RetransCounter=[0 0 0 0 0];
    
    option = simset('solver', 'ode4', 'FixedStep', delta_t);
    sim('HeatExchanger.mdl', [0 Tf]);
    %sim('SmAHTRHX_wcps.slx', [0 Tf]);
    
%     filename = strcat('DoublePlant_PS_INI3_RSSI74_',num2str(k)); 
%     save(filename);
end


toc

%zzz1=[];
%figure
%plot(TIME,zzz1)

% figure
% plot(TIME,DOUT1)

% figure
% plot(TIME,PumpOUT1)
% max(L1OUT)
% max(L2OUT)
% max(BASINOUT)