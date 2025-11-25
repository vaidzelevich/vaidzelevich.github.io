size(0, 10mm);

pair o1 = (0, 0);
label("$T_{0}$", o1);
pair o2 = (5.5, 0);
label("$T_{1}$", o2);
pair o3 = (11, 0);
label("$T_{2}$", o3);

draw(circle(o1, 1));
draw(circle(o2, 1));
draw(circle(o3, 1));

label(Label("$B_{0}$", align=dir(180)), o1 - (1, 0));
label(Label("$G_{0}$", align=dir(0)), o1 + (1, 0));

label(Label("$B_{1}$", align=dir(180)), o2 - (1, 0));
label(Label("$G_{1}$", align=dir(0)), o2 + (1, 0));

label(Label("$B_{2}$", align=dir(180)), o3 - (1, 0));
label(Label("$G_{2}$", align=dir(0)), o3 + (1, 0));
