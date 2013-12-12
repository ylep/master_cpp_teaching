% -*- octave -*-

function res = im_lin_color_trans(img, mat)

product = zeros(size(img));
res = zeros(size(img));
for i = 1:3
  for j = 1:3
    product(:, :, j) = mat(i, j) .* img(:, :, j);
  endfor
  res(:, :, i) = sum(product, 3);
endfor