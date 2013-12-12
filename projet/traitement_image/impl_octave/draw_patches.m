function ret = draw_patches(src, patches)

colors = rainbow(4);
ret = src;

for i=1:size(patches, 3)
  x1 = patches(1, 1, i);
  y1 = patches(2, 1, i);
  x2 = patches(1, 2, i);
  y2 = patches(2, 2, i);
  for j=1:3
    ret(x1, y1:y2, j) = colors(i, j);
    ret(x2, y1:y2, j) = colors(i, j);
    ret(x1:x2, y1, j) = colors(i, j);
    ret(x1:x2, y2, j) = colors(i, j);
  endfor
endfor
