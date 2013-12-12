% -*- octave -*-

function dst = color_transfer(src, tgt)

[tgt_mean, tgt_stddev] = im_chan_stat(tgt);
dst = color_transfer_stat(src, tgt_mean, tgt_stddev);
