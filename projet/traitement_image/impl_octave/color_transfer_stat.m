% -*- octave -*-

function dst = color_transfer_stat(src, tgt_mean, tgt_stddev)

[src_mean, src_stddev] = im_chan_stat(src);

dst = do_color_transfer(src, src_mean, src_stddev, tgt_mean, tgt_stddev);
