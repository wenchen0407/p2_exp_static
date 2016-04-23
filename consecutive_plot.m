figure(1);

load('control_consecutiveLostEvery0.1s.mat');
plot(TotalHeatTransfer.time,TotalHeatTransfer.data, 'Color', 'green');

hold on;
load('control_consecutiveLostEvery1s.mat');
plot(TotalHeatTransfer.time,TotalHeatTransfer.data, 'Color', 'blue');

hold on;
load('control_consecutiveLostEvery10s.mat');
plot(TotalHeatTransfer.time,TotalHeatTransfer.data, 'Color', 'cyan');

hold on;
load('noErrorDelay0.4.mat');
plot(TotalHeatTransfer.time,TotalHeatTransfer.data, 'Color', 'red');

hold on;
load('noErrornoDelay.mat');
plot(TotalHeatTransfer.time,TotalHeatTransfer.data, 'Color', 'black');

legend('consecutive lost every 0.1s(green) dr=0.09', 'consecutive lost every 1s(blue) dr=0.5', 'consecutive lost every 10s(cyan) dr=0.9', 'no error delay 0.4(red)', 'no error no delay(black)');
title('One heat exchanger system power output');
xlabel('time(s)');

figure(3);

load('nonconsecutiveLost0.5.mat');
plot(TotalHeatTransfer.time,TotalHeatTransfer.data, 'Color', 'red');

hold on;
load('control_consecutiveLostEvery1s.mat');
plot(TotalHeatTransfer.time,TotalHeatTransfer.data, 'Color', 'blue');

hold on;
load('noErrornoDelay.mat');
plot(TotalHeatTransfer.time,TotalHeatTransfer.data, 'Color', 'black');

legend('non consecutive lost(red) dr=0.5', 'consecutive lost every 1s(blue) dr=0.5', 'no error no delay(black)');
title('One heat exchanger system power output');
xlabel('time(s)');