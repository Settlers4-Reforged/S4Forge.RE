#ifndef TRI_H
#define TRI_H

// address=[0x2f90e70]
void _TRI_init_engine(int);
// address=[0x2f90eea]
void _TRI_calculate_LUT_from_palette(void *, void *);
// address=[0x2f90efa]
void _TRI_set_window();
// address=[0x2f90f2b]
void _TRI_draw_triangle(D3DTLVERTEX *, D3DTLVERTEX *, D3DTLVERTEX *, unsigned char *, int);
// address=[0x2f90f6f]
void clip_polygon_2d_2_xtras();
// address=[0x2f914f4]
void calc_texture_polygon();
// address=[0x2f91b04]
void calc_constant_slope_pow8();
// address=[0x2f91cac]
void draw_texture_polygon();
// address=[0x2f92494]
extern void *_TRI_palette_LUT;
// address=[0x2f92498]
void init_8bit_picture_palette();
// address=[0x2f924c8]
void init_FPU();

#endif // TRI_H
