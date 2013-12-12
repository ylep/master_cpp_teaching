% -*- octave -*-

function [dsts, means, stddevs] = color_transfer_patches(src, tgt, srcpatches, tgtpatches)

nb_patches = size(srcpatches, 3);

dsts = zeros([nb_patches, size(src)]);
means = zeros(3, nb_patches);
stddevs = zeros(3, nb_patches);
for patch_nb=1:nb_patches
  x1 = srcpatches(1, 1, patch_nb);
  y1 = srcpatches(2, 1, patch_nb);
  x2 = srcpatches(1, 2, patch_nb);
  y2 = srcpatches(2, 2, patch_nb);
  [src_mean, src_stddev] = im_chan_stat(src(x1:x2, y1:y2, :));
  x1 = tgtpatches(1, 1, patch_nb);
  y1 = tgtpatches(2, 1, patch_nb);
  x2 = tgtpatches(1, 2, patch_nb);
  y2 = tgtpatches(2, 2, patch_nb);
  [tgt_mean, tgt_stddev] = im_chan_stat(tgt(x1:x2, y1:y2, :));
  dsts(patch_nb, :, :, :) = do_color_transfer(src, ...
                                       src_mean, src_stddev, ...
                                       tgt_mean, tgt_stddev);
  means(:, patch_nb) = src_mean;
  stddevs(:, patch_nb) = src_stddev;
endfor
