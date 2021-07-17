clear all;close all;
dx=0.001;
x_min=-1;
x_max=1;
x=x_min:dx:x_max-dx;
N=4;
q=(x_max-x_min)/(2^N);
xq=q*floor((x)/q)+q/2;
qe=x-xq;
[h,scl]=hist(qe,10);
figure;bar(scl,h);

xlabel('quantization region');
ylabel('freq of occr');
np_m=std(qe)^2;
np_c=(q^2)/12
