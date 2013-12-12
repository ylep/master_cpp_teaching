% -*- octave -*-

function [chan_mean, chan_stddev] = im_chan_stat(img)

chan_mean = zeros(3, 1);
chan_stddev = zeros(3, 1);

for chan = 1:3
  chan_mean(chan) = mean(img(:, :, chan)(:));
  chan_stddev(chan) = std(img(:, :, chan)(:));
endfor
