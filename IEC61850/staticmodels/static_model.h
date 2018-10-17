/*
 * static_model.h
  *
 */

#ifndef STATIC_MODEL_H_
#define STATIC_MODEL_H_

#if defined (MR771)						// ������ � ��������� �������
#include "static_model_MR771.h"
#endif
#if defined (MR761)	|| defined (MR762) || defined (MR763)
#include "static_model_MR76x.h"
#endif
#if defined (MR801)
#include "static_model_MR801.h"
#endif
#if defined (MR901) || defined (MR902)
#include "static_model_MR901_902.h"
#endif

#if defined (MR5_700)
#include "static_model_MR5_700.h"
#endif
#if defined (MR5_600)
#include "static_model_MR5_600.h"
#endif
#if defined (MR5_500)
#include "static_model_MR5_500.h"
#endif
#if defined (MR851)
#include "static_model_MR851.h"
#endif
#if defined	(MR741)
#include "static_model_MR741.h"
#endif
#endif /* STATIC_MODEL_H_ */

