function factors = blend_factors(src, means, stddevs)

nb_patches = size(means, 2);
factors = zeros([nb_patches, size(src)(1:2)]);

for patch_nb=1:nb_patches
  diff = zeros(size(src));
  for chan=1:3
    diff(:, :, chan) = (src(:, :, chan) - means(chan, patch_nb)) ./ stddevs(chan, patch_nb);
  endfor
%  patch_stddev = sqrt(sum(stddevs(patch_nb, :) .^ 2));
%  factors(patch_nb, :, :) = sqrt(sum(diff .^ 2, 3)) ./ patch_stddev;
  factors(patch_nb, :, :) = sqrt(sum(diff .^ 2, 3));
endfor
factors = 1 ./ factors;