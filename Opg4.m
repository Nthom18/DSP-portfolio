syms z
H(z)=(0.02298+0.02001*z^(-2)-0.02001*z^(-4)-0.02298*z^(-6))/(1+2.631*z^(-2)+2.327*z^(-4)+0.69013*z^(-6));

fplot(H(z), [-10 10],'r')

ax = gca;
ax.YAxisLocation = 'origin';
ax.XAxisLocation = 'origin';

xlabel('Frequency');
ylabel('Amplitude');
