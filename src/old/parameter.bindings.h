
/* signal noise properties */
#ifdef BRECS_PIXMEAN
static float const pixmean = BRECS_PIXMEAN;
#else
#define BRECS_PIXMEAN 500
static float const pixmean = 500.0f;
#endif

#ifdef BRECS_PIXSTD
static float const pixstd = BRECS_PIXSTD;
#else
static float const pixstd = 200.0f;
#endif

#ifdef BRECS_RHO
static float const rho = BRECS_RHO;
#else
static float const rho = 0.001f;
#endif

/* Sizes of the images */

#ifdef BRECS_KERSIZE
static int const kersize = BRECS_KERSIZE;
#else
#define BRECS_KERSIZE 8
static int const kersize = 8;
#endif

#ifdef BRECS_KERSIZEZ
static int const kersizez = BRECS_KERSIZEZ;
#else
#define BRECS_KERSIZEZ 1
static int const kersizez = 1;
#endif

#ifdef BRECS_PIXSDIV
static int const pixsdiv = BRECS_PIXSDIV;
#else
#define BRECS_PIXSDIV 8
static int const pixsdiv = 8;
#endif

#ifdef BRECS_PIXSDIVZ
static int const pixsdivz = BRECS_PIXSDIVZ;
#else
#define BRECS_PIXSDIVZ 1
static int const pixsdivz = 1;
#endif

static unsigned const kersize2 = BRECS_KERSIZE * BRECS_KERSIZE;
static unsigned const kersize3 = BRECS_KERSIZE * BRECS_KERSIZE * BRECS_KERSIZEZ;

static unsigned const pixsdiv2 = BRECS_PIXSDIV * BRECS_PIXSDIV;
static unsigned const pixsdiv3 = BRECS_PIXSDIV * BRECS_PIXSDIV * BRECS_PIXSDIVZ;

#ifdef BRECS_SPIXNM
static float const spixnm = BRECS_SPIXNM;
#else
static float const spixnm = 133.0;
#endif

#ifdef BRECS_SPIXZNM
static float const spixznm = BRECS_SPIXZNM;
#else
static float const spixznm = 300.0;
#endif

#ifdef BRECS_MESOFFSET
static float const mesoffset = BRECS_MESOFFSET;
#else
static float const mesoffset = 80;
#endif

#ifdef BRECS_MESAMPLI
static float const mesampli = BRECS_MESAMPLI;
#else
static float const mesampli = 20;
#endif

#ifdef BRECS_NOISEOFFSET
static float const noiseoffset = BRECS_NOISEOFFSET;
#else
static float const noiseoffset = 1;
#endif

#ifdef BRECS_NBITER
static int const nbiter = BRECS_NBITER;
#else
static int const nbiter = 200;
#endif

#ifdef BRECS_PREFACRADCC
static float const prefacradcc = BRECS_PREFACRADCC;
#else
static float const prefacradcc = 1.0;
#endif

#ifdef BRECS_CONVOLPIXTHR
static float const convolpixthr = BRECS_CONVOLPIXTHR;
#else
static float const convolpixthr = 40.0;
#endif


#ifdef BRECS_AINITPFACT
static float const Ainit = BRECS_AINITPFACT / (BRECS_PIXMEAN * BRECS_PIXMEAN);
#else
static float const Ainit = 1.0 / (BRECS_PIXMEAN * BRECS_PIXMEAN);
#endif

#ifdef BRECS_MEANBACK
const float meanback = BRECS_MEANBACK;
#else
const float meanback = 0;
#endif

#ifdef BRECS_LOCAINTENSTHR
const float locaintensthr = BRECS_LOCAINTENSTHR;
#else
const float locaintensthr = 1000;
#endif

#ifdef BRECS_OVERLAYMAXINT
const float overlaymaxint = BRECS_OVERLAYMAXINT;
#else
const float overlaymaxint = 50.4;
#endif

#ifdef BRECS_OVERLAYMININT
const float overlayminint = BRECS_OVERLAYMININT;
#else
const float overlayminint = 0.1;
#endif

#ifdef BRECS_RELERRTHR
const float relerrthr = BRECS_RELERRTHR;
#else
const float relerrthr = 1e-3;
#endif

#ifdef BRECS_NBINTERNLOOP
const float nbinternloop = BRECS_NBINTERNLOOP;
#else
const float nbinternloop = 1;
#endif


#ifdef BRECS_DAMP1
const float damp1 = BRECS_DAMP1;
#else
const float damp1 = 0.05;
#endif

#ifdef BRECS_DAMP2
const float damp2 = BRECS_DAMP2;
#else
const float damp2 = 0.1;
#endif

#undef BRECS_PIXMEAN
#undef BRECS_PIXSTD
#undef BRECS_RHO
#undef BRECS_KERSIZE
#undef BRECS_KERSIZEZ
#undef BRECS_PIXSDIV
#undef BRECS_PIXSDIVZ
#undef BRECS_SPIXNM
#undef BRECS_SPIXZNM
#undef BRECS_MESOFFSET
#undef BRECS_MESAMPLI
#undef BRECS_NOISEOFFSET
#undef BRECS_NBITER
#undef BRECS_PREFACRADCC
#undef BRECS_CONVOLPIXTHR
#undef BRECS_AINITPFACT
#undef BRECS_MEANBACK
#undef BRECS_LOCAINTENSTHR
#undef BRECS_OVERLAYMAXINT
#undef BRECS_OVERLAYMININT
#undef BRECS_RELERRTHR
#undef BRECS_NBINTERNLOOP
#undef BRECS_DAMP1
#undef BRECS_DAMP2

