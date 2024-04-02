#ifndef CONFIG_H
#define CONFIG_H

// #include <cmath>

#ifdef PRINT_CPP

static const char *OP_COLOR = "crimson";
static const char *NM_COLOR = "lightskyblue";
static const char *VR_COLOR = "green";
static const char *FN_COLOR = "orange";

static const char *OP_SHAPE = "Mrecord";
static const char *NM_SHAPE = "Mrecord";
static const char *VR_SHAPE = "Mrecord";
static const char *FN_SHAPE = "Mrecord";
#endif

#ifdef CALCULATE_CPP

double VarArray[] {
    2,
    77,
    345,
};

#endif

#endif // !CONFIG_H