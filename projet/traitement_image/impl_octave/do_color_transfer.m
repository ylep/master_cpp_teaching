% -*- octave -*-

function dst = do_color_transfer(src, ...
                                 src_mean, src_stddev, ...
                                 tgt_mean, tgt_stddev)

dst = zeros(size(src));
for chan = 1:3
  centered = src(:,:,chan) - src_mean(chan);
  scaled = tgt_stddev(chan) / src_stddev(chan) * centered;
  dst(:,:,chan) = scaled + tgt_mean(chan);
endfor
