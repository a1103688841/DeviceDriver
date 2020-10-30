/**************************************************************************************************
* ����:                              �Զ��崮
*        
* �ļ�:  StringReform.c
*        
* ˵��:  
*        
* ����:  ���Ϸ�  10/27/2020
**************************************************************************************************/

#define __STRINGREFORM_C__
/* ------------------------------------------- include ----------------------------------------- */


/* ------------------------------------- define/typedef/enum ----------------------------------- */


/* ------------------------------------------- variable ---------------------------------------- */


/* -------------------------------------------static funtion ----------------------------------------- */
#ifdef STATIC_FUNCTION
#endif	/* STATIC_FUNCTION */


/* -------------------------------------------global funtion ----------------------------------------- */
#ifdef GLOBAL_FUNCTION
#endif	/* GLOBAL_FUNCTION */
/**************************************************************************************************
*	 ����
* 1����ӡ����   ������Ĵ�ӡ�߼����������е㲻һ����
* 2���ڲ���������
* 3) ʹ��ʾ��   ��20201022�汾��
**************************************************************************************************
*1�� ��ӡ����
**************************************************************************************************/
//����ַ���T
void StrPrintTraverse(String T)
{ 
	int i;
	for(i=1;i<=T[0];i++)
	{
		printf("%c",T[i]);
	}
	printf("\n");
}
/*  ���Next����ֵ�� */
void NextPrint(int next[],int length)
{ 
	int i;
	for(i=1;i<=length;i++)
	{
		printf("%d",next[i]);
	}
	printf("\n");
}

//����һ����ֵ����chars�Ĵ�T
StrStatus strAssign(String T,char *chars)
{ 
	int i;
	//���ȳ���
	if(strlen(chars) > STR_MAXSIZE)
	{
		return ERROR;
	}
	else
	{
		T[0] = strlen(chars);
		for(i=1;i<=T[0];i++)
			T[i]=*(chars+i-1);
		return OK;
	}
}



/* ��SΪ�մ�,�򷵻�TRUE,���򷵻�FALSE */
StrStatus strEmpty(String S)
{ 
	return ((S[0]==0)? (TRUE):(FALSE));
}

/* ��ʼ����:��S���ڡ��������:��S��Ϊ�մ� */
StrStatus strClear(String S)
{ 
	S[0]=0;/*  ���Ϊ�� */
	return OK;
}
/* ���ش���Ԫ�ظ��� */
int strLength(String S)
{ 
	return S[0];
}
// �ɴ�S���Ƶô�T 
StrStatus strCopy(String T,String S)
{ 
	int i;
	for(i=0;i<=S[0];i++)
	{
		T[i]=S[i];
	}
	return OK;
}
/*  ��ʼ����: ��S��T���� */
/*  �������: ��S>T,�򷵻�ֵ>0;��S=T,�򷵻�ֵ=0;��S<T,�򷵻�ֵ<0 */
int strCompare(String S, String T)
{ 
	int i;
	for(i=1; i <= S[0] && i <= T[0]; ++i)
	{
		if(S[i]!=T[i])
		{
			return S[i]-T[i];
		}
	}
	return S[0]-T[0];
}

/* ��T����S1��S2���Ӷ��ɵ��´�����δ�ضϣ��򷵻�TRUE������FALSE */
StrStatus strConcat(String T, String S1, String S2)
{
	int i;
	
	if(S1[0]+S2[0]<=STR_MAXSIZE)
	{ 
		/*  δ�ض� */
		//T[0]�ǳ���
		for(i=1;i<=S1[0];i++)
		{
			T[i]=S1[i];
		}
		for(i=1;i<=S2[0];i++)
		{
			T[S1[0]+i]=S2[i];
		}
		T[0]=S1[0]+S2[0];
		return TRUE;
	}
	else
	{ /*  �ض�S2 */
		for(i=1;i<=S1[0];i++)
		{
			T[i]=S1[i];
		}
		for(i = 1; i <= STR_MAXSIZE-S1[0]; i++)
		{
			T[S1[0]+i] = S2[i];
		}
		T[0] = STR_MAXSIZE;
		return FALSE;
	}
}

/* ��Sub���ش�S�ĵ�pos���ַ��𳤶�Ϊlen���Ӵ��� */
StrStatus strCutOut(String Sub,String S,int pos,int len)
{
	int i;
	//�±곬����
	if( pos<1 || pos>S[0] || len<0|| len>S[0]-pos+1)
	{
		return ERROR;
	}
	for(i=1; i<=len; i++)
	{
		Sub[i] = S[pos+i-1];
	}
	Sub[0] = len;
	return OK;
}

/* �����Ӵ�T������S�е�pos���ַ�֮���λ�á���������,��������ֵΪ0�� */
/* ����,T�ǿ�,1��pos��StrLength(S)�� */
//���ص�ƥ���㷨
int strSearchSubStrIndex(String S, String T, int pos) 
{
	int i = pos;			/* i��������S�е�ǰλ���±�ֵ����pos��Ϊ1�����posλ�ÿ�ʼƥ�� */
	int j = 1;				/* j�����Ӵ�T�е�ǰλ���±�ֵ */
	//�±곬����
	if (pos < 1 || S[0] < T[0]+pos)
	{
		return 0;
	}
	while (i <= S[0] && j <= T[0]) /* ��iС��S�ĳ��Ȳ���jС��T�ĳ���ʱ��ѭ������ */
	{
		if (S[i] == T[j]) 	/* ����ĸ�������� */
      	{
      		//��ʼ��ֵ1��ƥ��+1������ʵ��һλ��������������жϳ���
			++i;
         	++j; 
      	} 
      	else 				/* ָ��������¿�ʼƥ�� */
      	{  
         	i = i-j+2;		/* i�˻ص��ϴ�ƥ����λ����һλ */
         	j = 1; 			/* j�˻ص��Ӵ�T����λ */
      	}      
	}
	//��ʼ��ֵ1������ƥ���һλ
	if (j > T[0])
	{
		return i-T[0];
	}
	else 
	{
		return 0;
	}
}


/*  TΪ�ǿմ���������S�е�pos���ַ�֮�������T��ȵ��Ӵ��� */
/*  �򷵻ص�һ���������Ӵ���S�е�λ�ã����򷵻�0 */
int strSearchSubStrIndex2(String S, String T, int pos) 
{
	int n,m,i;
	String sub;
	//�±곬����
	if (pos < 1 || S[0] < T[0]+pos)
	{
		return 0;
	}
	n = strLength(S);	/* �õ�����S�ĳ��� */
	m = strLength(T);	/* �õ��Ӵ�T�ĳ��� */
	i = pos;
	while (i <= n-m+1) 
	{
		strCutOut(sub, S, i, m);	/* ȡ�����е�i��λ�ó�����T��ȵ��Ӵ���sub */
		if (strCompare(sub,T) != 0)    /* ������������ */
		{
			++i;
		}
		else 				/* ���������� */
		{
			return i;		/* �򷵻�iֵ */
		}
	}
	return 0;	/* �����Ӵ���T��ȣ�����0 */
}


/*  ��ʼ����: ��S��T����,1��pos��StrLength(S)+1 */
/*  �������: �ڴ�S�ĵ�pos���ַ�֮ǰ���봮T����ȫ���뷵��TRUE,���ֲ��뷵��FALSE */
StrStatus strInsert(String S,int pos,String T)
{ 
	int i;
	if(pos<1 || pos>S[0]+1)
	{
		return ERROR;
	}
	if( S[0] + T[0] <= STR_MAXSIZE)
	{ /*  ��ȫ���� */
		//����
		////�����Ƶľ������Ҫ����ĸ���λ�ã����渱����ֵ���Ը���
		////����Ǽ��ź��ƣ�ǰ����
		for(i=S[0]; i>=pos; i--)
		{
			S[i+T[0]]=S[i];
		}
		//����
		for(i=pos; i<pos+T[0]; i++)
		{
			S[i]=T[i-pos+1];
		}
		//�޸ĳ���
		S[0]=S[0]+T[0];
		return TRUE;
	}
	else
	{ /*  ���ֲ��� */
		//����
		////�����Ƶľ������Ҫ����ĸ���λ�ã����渱����ֵ���Ը���
		////����Ǽ��ź��ƣ������
		for(i=STR_MAXSIZE; i<=pos; i--)
		{
			S[i]=S[i-T[0]];
		}
		//����
		////���Ƕ��ƶ���λ��
		for(i=pos; i<pos+T[0]; i++)
		{
			S[i]=T[i-pos+1];
		}
		//�޸ĳ���
		S[0]=STR_MAXSIZE;
		return FALSE;
	}
}

/*  ��ʼ����: ��S����,1��pos��StrLength(S)-len+1 */
/*  �������: �Ӵ�S��ɾ����pos���ַ��𳤶�Ϊlen���Ӵ� */
StrStatus strDelete(String S,int pos,int len)
{ 
	int i;
	if(pos<1 || pos>S[0]-len+1 || len<0)
	{
		return ERROR;
	}
	//ǰ��
	for(i=pos+len; i<=S[0]; i++)
	{
		S[i-len] = S[i];
	}
	S[0]- = len;
	return OK;
}

/*  ��ʼ����: ��S,T��V����,T�Ƿǿմ����˺����봮�Ĵ洢�ṹ�޹أ� */
/*  �������: ��V�滻����S�г��ֵ�������T��ȵĲ��ص����Ӵ� */
StrStatus Replace(String S,String T,String V)
{ 
	int i=1; /*  �Ӵ�S�ĵ�һ���ַ�����Ҵ�T */
	if(strEmpty(T)) /*  T�ǿմ� */
	{
		return ERROR;
	}
	do
	{
		i= strSearchSubStrIndex(S,T,i); 	/*  ���iΪ����һ��i֮���ҵ����Ӵ�T��λ�� */
		if(i) 								/*  ��S�д��ڴ�T */
		{
			strDelete(S,i,strLength(T)); 	/*  ɾ���ô�T */
			strInsert(S,i,V);  				/*  ��ԭ��T��λ�ò��봮V */
			//��ͷ��Ҳ�ǿ��Ե�
			i+=strLength(V);  				/*  �ڲ���Ĵ�V����������Ҵ�T */
		}
	}while(i);
	return OK;
}




/**************************************************************************************************
* ����:                                   KMP
* ˵��: 
* ����:  
* ����:  ���Ϸ�  10/27/2020
**************************************************************************************************/
/* ͨ�����㷵���Ӵ�T��next���顣 */
void get_next(String T, int *next) 
{
	int i,j;
  	i=1;
  	j=0;
  	next[1]=0;
  	while (i<T[0])  /* �˴�T[0]��ʾ��T�ĳ��� */
 	{
    	if(j==0 || T[i]== T[j]) 	/* T[i]��ʾ��׺�ĵ����ַ���T[j]��ʾǰ׺�ĵ����ַ� */
		{
      		++i;  
			++j;  
			next[i] = j;
    	} 
		else 
			j= next[j];	/* ���ַ�����ͬ����jֵ���� */
  	}
}

/* �����Ӵ�T������S�е�pos���ַ�֮���λ�á��������ڣ���������ֵΪ0�� */
/*  T�ǿգ�1��pos��StrLength(S)�� */
int Index_KMP(String S, String T, int pos) 
{
	int i = pos;		/* i��������S�е�ǰλ���±�ֵ����pos��Ϊ1�����posλ�ÿ�ʼƥ�� */
	int j = 1;			/* j�����Ӵ�T�е�ǰλ���±�ֵ */
	int next[255];		/* ����һnext���� */
	get_next(T, next);	/* �Դ�T���������õ�next���� */
	while (i <= S[0] && j <= T[0]) /* ��iС��S�ĳ��Ȳ���jС��T�ĳ���ʱ��ѭ������ */
	{
		if (j==0 || S[i] == T[j]) 	/* ����ĸ�����������������㷨������j=0�ж� */
      	{
         	++i;
         	++j; 
      	} 
      	else 			/* ָ��������¿�ʼƥ�� */
      	 	j = next[j];/* j�˻غ��ʵ�λ�ã�iֵ���� */
	}
	if (j > T[0]) 
		return i-T[0];
	else 
		return 0;
}

/* ��ģʽ��T��next��������ֵ����������nextval */
void get_nextval(String T, int *nextval) 
{
  	int i,j;
  	i=1;
  	j=0;
  	nextval[1]=0;
  	while (i<T[0])  /* �˴�T[0]��ʾ��T�ĳ��� */
 	{
    	if(j==0 || T[i]== T[j]) 	/* T[i]��ʾ��׺�ĵ����ַ���T[j]��ʾǰ׺�ĵ����ַ� */
		{
      		++i;  
			++j;  
			if (T[i]!=T[j])      /* ����ǰ�ַ���ǰ׺�ַ���ͬ */
				nextval[i] = j;	/* ��ǰ��jΪnextval��iλ�õ�ֵ */
      		else 
				nextval[i] = nextval[j];	/* �����ǰ׺�ַ���ͬ����ǰ׺�ַ��� */
											/* nextvalֵ��ֵ��nextval��iλ�õ�ֵ */
    	} 
		else 
			j= nextval[j];			/* ���ַ�����ͬ����jֵ���� */
  	}
}

int Index_KMP1(String S, String T, int pos) 
{
	int i = pos;		/* i��������S�е�ǰλ���±�ֵ����pos��Ϊ1�����posλ�ÿ�ʼƥ�� */
	int j = 1;			/* j�����Ӵ�T�е�ǰλ���±�ֵ */
	int next[255];		/* ����һnext���� */
	get_nextval(T, next);	/* �Դ�T���������õ�next���� */
	while (i <= S[0] && j <= T[0]) /* ��iС��S�ĳ��Ȳ���jС��T�ĳ���ʱ��ѭ������ */
	{
		if (j==0 || S[i] == T[j]) 	/* ����ĸ�����������������㷨������j=0�ж� */
      	{
         	++i;
         	++j; 
      	} 
      	else 			/* ָ��������¿�ʼƥ�� */
      	 	j = next[j];/* j�˻غ��ʵ�λ�ã�iֵ���� */
	}
	if (j > T[0]) 
		return i-T[0];
	else 
		return 0;
}



#if 0
int main()
{
	
	int i,j;
	StrStatus k;
	char s;
	String t,s1,s2;
	printf("�����봮s1: ");
	
	k=StrAssign(s1,"abcd");
	if(!k)
	{
		printf("��������MAXSIZE(=%d)\n",MAXSIZE);
		exit(0);
	}
	printf("����Ϊ%d ���շ�%d(1:�� 0:��)\n",StrLength(s1),StrEmpty(s1));
	StrCopy(s2,s1);
	printf("����s1���ɵĴ�Ϊ: ");
	StrPrint(s2);
	printf("�����봮s2: ");
	
	k=StrAssign(s2,"efghijk");
	if(!k)
	{
		printf("��������MAXSIZE(%d)\n",MAXSIZE);
		exit(0);
	}
	i=StrCompare(s1,s2);
	if(i<0)
		s='<';
	else if(i==0)
		s='=';
	else
		s='>';
	printf("��s1%c��s2\n",s);
	k=Concat(t,s1,s2);
	printf("��s1���Ӵ�s2�õ��Ĵ�tΪ: ");
	StrPrint(t);
	if(k==FALSE)
		printf("��t�нض�\n");
	ClearString(s1);
	printf("��Ϊ�մ���,��s1Ϊ: ");
	StrPrint(s1);
	printf("����Ϊ%d ���շ�%d(1:�� 0:��)\n",StrLength(s1),StrEmpty(s1));
	printf("��t���Ӵ�,�������Ӵ�����ʼλ��,�Ӵ�����: ");

	i=2;
	j=3;
	printf("%d,%d \n",i,j);

	k=SubString(s2,t,i,j);
	if(k)
	{
		printf("�Ӵ�s2Ϊ: ");
		StrPrint(s2);
	}
	printf("�Ӵ�t�ĵ�pos���ַ���,ɾ��len���ַ���������pos,len: ");
	
	i=4;
	j=2;
	printf("%d,%d \n",i,j);


	StrDelete(t,i,j);
	printf("ɾ����Ĵ�tΪ: ");
	StrPrint(t);
	i=StrLength(s2)/2;
	StrInsert(s2,i,t);
	printf("�ڴ�s2�ĵ�%d���ַ�֮ǰ���봮t��,��s2Ϊ:\n",i);
	StrPrint(s2);
	i=Index(s2,t,1);
	printf("s2�ĵ�%d����ĸ���t��һ��ƥ��\n",i);
	SubString(t,s2,1,1);
	printf("��tΪ��");
	StrPrint(t);
	Concat(s1,t,t);
	printf("��s1Ϊ��");
	StrPrint(s1);
	Replace(s2,t,s1);
	printf("�ô�s1ȡ����s2�кʹ�t��ͬ�Ĳ��ص��Ĵ���,��s2Ϊ: ");
	StrPrint(s2);


	return 0;
}
#endif

