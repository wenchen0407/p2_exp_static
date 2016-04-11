
clear all
close all

load('step_data.mat')

hxfer = TotalHeatTransfer.data;
t = TotalHeatTransfer.time;

figure(1)
subplot(2,1,1)
plot(t,hxfer,t,refinput.data)
xlabel('time')
ylabel('HX across PHX, MW')
title('heat transfer across PHX subjected to ramp input of 5%/min')
legend('HX','reference','location','best')

subplot(2,1,2)
plot(t,delay.data(:,2))
xlabel('time')
ylabel('Primary PHX temperature out delay, seconds')
title('PHX Primary temp out delay - only variable parameter used in ctrl calc')

figure(2)
subplot(2,2,1)
plot(t,CONTROL_ACTION.data)
title('Control action')

subplot(2,2,2)
plot(t,primarytempout.data)
xlabel('time')
ylabel('temperature, deg. C')
title('Primary Temperature out of HX')

%figure(4)
%plot(t,delay.data(:,1))

%figure(5)
%plot(t,delay.data(:,3))

subplot(2,2,[3,4])
plot(t,Signal_measure(:,2))
xlabel('time')
ylabel('Temperature, Deg. C')
title('PHXtemp out measurement w/ noise')