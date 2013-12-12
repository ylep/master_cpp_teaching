function dst = blend_dsts(dsts, factors)

nb_patches = size(dsts, 1);
im_shape = size(dsts)(2:3);
sumfactors = reshape(sum(factors, 1), im_shape);

dst = zeros(size(dsts)(2:4));

for chan=1:3
  dst(:, :, chan) = reshape(sum(dsts(:, :, :, chan) .* factors, 1), \
                            im_shape) ./ sumfactors;
endfor
