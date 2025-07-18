/*******************************************************************************

License: 
This software and/or related materials was developed at the National Institute
of Standards and Technology (NIST) by employees of the Federal Government
in the course of their official duties. Pursuant to title 17 Section 105
of the United States Code, this software is not subject to copyright
protection and is in the public domain. 

This software and/or related materials have been determined to be not subject
to the EAR (see Part 734.3 of the EAR for exact details) because it is
a publicly available technology and software, and is freely distributed
to any interested party with no licensing requirements.  Therefore, it is 
permissible to distribute this software as a free download from the internet.

Disclaimer: 
This software and/or related materials was developed to promote biometric
standards and biometric technology testing for the Federal Government
in accordance with the USA PATRIOT Act and the Enhanced Border Security
and Visa Entry Reform Act. Specific hardware and software products identified
in this software were used in order to perform the software development.
In no case does such identification imply recommendation or endorsement
by the National Institute of Standards and Technology, nor does it imply that
the products and equipment identified are necessarily the best available
for the purpose.

This software and/or related materials are provided "AS-IS" without warranty
of any kind including NO WARRANTY OF PERFORMANCE, MERCHANTABILITY,
NO WARRANTY OF NON-INFRINGEMENT OF ANY 3RD PARTY INTELLECTUAL PROPERTY
or FITNESS FOR A PARTICULAR PURPOSE or for any purpose whatsoever, for the
licensed product, however used. In no event shall NIST be liable for any
damages and/or costs, including but not limited to incidental or consequential
damages of any kind, including economic damage or injury to property and lost
profits, regardless of whether NIST shall be advised, have reason to know,
or in fact shall know of the possibility.

By using this software, you agree to bear all risk relating to quality,
use and performance of the software and/or related materials.  You agree
to hold the Government harmless from any claim arising from your use
of the software.

*******************************************************************************/


/***********************************************************************
      LIBRARY: IHEAD - IHead Image Utilities

      FILE:    WRITIHDR.C
      AUTHOR:  Michael Garris
      DATE:    02/08/1990
      UPDATED: 03/14/2005 by MDG

      Contains routines responsible for writing the contents
      of an IHead header to an open file.

      ROUTINES:
#cat: writeihdr - writes the contents of an IHead structure to an open
#cat:             file pointer.

***********************************************************************/

#include <stdio.h>
#include "ihead.h""ihead.h"

/************************************************************/
/* Writeihdr() writes the fixed length field and the header */
/* passed to the given file pointer.                        */
/************************************************************/
void writeihdr(FILE *fp, IHEAD *ihead)
{
   int i;
   char lenstr[SHORT_CHARS];

   for (i = 0; i < SHORT_CHARS; i++)
      lenstr[i] = '\0';
   /* creates a string from of header size */
   sprintf(lenstr,"%d",sizeof(IHEAD));
   /* writes the length string in headerto the file */
   fwrite(lenstr,sizeof(char),SHORT_CHARS,fp);
   /* writes the given header to the file */
   fwrite(ihead,sizeof(IHEAD),1,fp);
}
