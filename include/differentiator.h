#ifndef DIFFERENTIATOR_H
#define DIFFERENTIATOR_H

#include "main.h"

#include <math.h>

typedef struct Array_t
{
    char  *arr_ptr;
    size_t size_arr;
} array_t;

enum ClassNodeType
{
    TpNm = 0,
    TpVr = 1,
    TpOp = 2,
    TpFn = 3,
    TpCn = 4,
};

enum ClassOperation
{
    OpAdd = 0,
    OpSub = 1,
    OpMul = 2,
    OpDiv = 3,
    OpPow  = 4 
};


enum ClassFunction {
    FnSin  = 0,
    FnCos  = 1,
    FnTg   = 2,
    FnCtg  = 3,
    FnSh   = 4,
    FnCh   = 5,
    FnLn   = 6,
    FnLg   = 7,
    FnLog  = 8,
    FnSqrt = 9,
    FnAsin = 10,
    FnAcos = 11,
    FnAtg  = 12,
    FnActg = 13,
    FnTh   = 14,
    FnCth  = 15,
    FnExp  = 16,
};

enum ClassConstant {
    CnE  = 0,
    CnPi = 1,
};

static const char *ArrayCn[] = {
    "e",
    "pi",
};

static const double ConstArray[] = {
    2.7,
    3.14,
};

static const char* ArrayFn[] = {
    "sin",
    "cos",
    "tg",
    "ctg",
    "sh",
    "ch",
    "ln",
    "lg",
    "log",
    "sqrt",
    "arcsin",
    "arccos",
    "arctg",
    "arcctg",
    "th",
    "cth",
    "exp",
};

static const char* ArrayTp[] = {
    "Num",
    "Variable",
    "Operation",
    "Function",
    "Constant",
};

static const char ArrayOp[] = {
    '+',
    '-',
    '*',
    '/',
    '^',
};

static const char ArrayVr[] = {
    'x',
    'y',
    'z',
};

enum ErrorCode {
    ERROR_UNKNOWN_NODE_TYPE      = 1,
    ERROR_UNKNOWN_OPERATION_TYPE = 2,
    ERROR_UNKNOWN_FUNCTION_TYPE  = 3,
};

#define MAX_LEN_FUNC_NAME 100

#define NTYPE      node->Type
#define LNODE      node->LeftNode
#define RNODE      node->RightNode
#define LNTYPE     node->LeftNode->Type
#define RNTYPE     node->RightNode->Type
#define OP_VR_TYPE node->Data.TypeOpVr

#define _DIFF(node) Differentiator(node, part)
#define _CPY(node)  Copy_Node     (node)

#define _NUM(val)          CreateNode(TpNm, (NodeData){.Num      = val  }, NULL , NULL )
#define _ADD(lnode, rnode) CreateNode(TpOp, (NodeData){.TypeOpVr = OpAdd}, lnode, rnode)
#define _SUB(lnode, rnode) CreateNode(TpOp, (NodeData){.TypeOpVr = OpSub}, lnode, rnode)
#define _MUL(lnode, rnode) CreateNode(TpOp, (NodeData){.TypeOpVr = OpMul}, lnode, rnode)
#define _DIV(lnode, rnode) CreateNode(TpOp, (NodeData){.TypeOpVr = OpDiv}, lnode, rnode)
#define _POW(lnode, rnode) CreateNode(TpOp, (NodeData){.TypeOpVr = OpPow}, lnode, rnode)

#define _LN(node)          CreateNode(TpFn, (NodeData){.TypeOpVr = FnLn  }, node, NULL)
#define _LG(node)          CreateNode(TpFn, (NodeData){.TypeOpVr = FnLg  }, node, NULL)
#define _LOG(node)         CreateNode(TpFn, (NodeData){.TypeOpVr = FnLog }, node, NULL)
#define _SIN(node)         CreateNode(TpFn, (NodeData){.TypeOpVr = FnSin }, node, NULL)
#define _COS(node)         CreateNode(TpFn, (NodeData){.TypeOpVr = FnCos }, node, NULL)
#define _TG(node)          CreateNode(TpFn, (NodeData){.TypeOpVr = FnTg  }, node, NULL)
#define _CTG(node)         CreateNode(TpFn, (NodeData){.TypeOpVr = FnCtg }, node, NULL)
#define _ASIN(node)        CreateNode(TpFn, (NodeData){.TypeOpVr = FnAsin}, node, NULL)
#define _ACOS(node)        CreateNode(TpFn, (NodeData){.TypeOpVr = FnAcos}, node, NULL)
#define _ATG(node)         CreateNode(TpFn, (NodeData){.TypeOpVr = FnTg  }, node, NULL)
#define _ACTG(node)        CreateNode(TpFn, (NodeData){.TypeOpVr = FnCtg }, node, NULL)
#define _SH(node)          CreateNode(TpFn, (NodeData){.TypeOpVr = FnSh  }, node, NULL)
#define _CH(node)          CreateNode(TpFn, (NodeData){.TypeOpVr = FnCh  }, node, NULL)
#define _TH(node)          CreateNode(TpFn, (NodeData){.TypeOpVr = FnTh  }, node, NULL)
#define _CTH(node)         CreateNode(TpFn, (NodeData){.TypeOpVr = FnCth }, node, NULL)
#define _SQRT(node)        CreateNode(TpFn, (NodeData){.TypeOpVr = FnSqrt}, node, NULL)
#define _EXP(node)         CreateNode(TpFn, (NodeData){.TypeOpVr = FnExp }, node, NULL)

int DTFunc(const char* fname);

DiffNode *CreateTreeRec(array_t *sarr, size_t *count);
size_t    SearchSizeFile(FILE *fp);
array_t  *CtorArray(FILE *fp_src);
int       SearchVar(DiffNode *node, int var);
int       equal(double num1, double num2);
DiffNode *Copy_Node(DiffNode *node);
DiffNode *CreateNode(char type, NodeData data, DiffNode *LeftNode, DiffNode *RightNode);
int       PrintNodesDot(FILE *fp, DiffNode *node);
int       DefinitionTypeVariableAndOperation(char ch);
char      DefinitionTypeNode(char *arr);

#endif
