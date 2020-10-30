/**************************************************************************************************
* 功能:                              自定义串
*        
* 文件:  StringReform.c
*        
* 说明:  
*        
* 作者:  日南方  10/27/2020
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
*	 汇总
* 1）打印函数   （这里的打印逻辑和其他的有点不一样）
* 2）内部操作函数
* 3) 使用示例   （20201022版本）
**************************************************************************************************
*1） 打印函数
**************************************************************************************************/
//输出字符串T
void StrPrintTraverse(String T)
{ 
	int i;
	for(i=1;i<=T[0];i++)
	{
		printf("%c",T[i]);
	}
	printf("\n");
}
/*  输出Next数组值。 */
void NextPrint(int next[],int length)
{ 
	int i;
	for(i=1;i<=length;i++)
	{
		printf("%d",next[i]);
	}
	printf("\n");
}

//生成一个其值等于chars的串T
StrStatus strAssign(String T,char *chars)
{ 
	int i;
	//长度超标
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



/* 若S为空串,则返回TRUE,否则返回FALSE */
StrStatus strEmpty(String S)
{ 
	return ((S[0]==0)? (TRUE):(FALSE));
}

/* 初始条件:串S存在。操作结果:将S清为空串 */
StrStatus strClear(String S)
{ 
	S[0]=0;/*  令串长为零 */
	return OK;
}
/* 返回串的元素个数 */
int strLength(String S)
{ 
	return S[0];
}
// 由串S复制得串T 
StrStatus strCopy(String T,String S)
{ 
	int i;
	for(i=0;i<=S[0];i++)
	{
		T[i]=S[i];
	}
	return OK;
}
/*  初始条件: 串S和T存在 */
/*  操作结果: 若S>T,则返回值>0;若S=T,则返回值=0;若S<T,则返回值<0 */
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

/* 用T返回S1和S2联接而成的新串。若未截断，则返回TRUE，否则FALSE */
StrStatus strConcat(String T, String S1, String S2)
{
	int i;
	
	if(S1[0]+S2[0]<=STR_MAXSIZE)
	{ 
		/*  未截断 */
		//T[0]是长度
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
	{ /*  截断S2 */
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

/* 用Sub返回串S的第pos个字符起长度为len的子串。 */
StrStatus strCutOut(String Sub,String S,int pos,int len)
{
	int i;
	//下标超界检测
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

/* 返回子串T在主串S中第pos个字符之后的位置。若不存在,则函数返回值为0。 */
/* 其中,T非空,1≤pos≤StrLength(S)。 */
//朴素的匹配算法
int strSearchSubStrIndex(String S, String T, int pos) 
{
	int i = pos;			/* i用于主串S中当前位置下标值，若pos不为1，则从pos位置开始匹配 */
	int j = 1;				/* j用于子串T中当前位置下标值 */
	//下标超界检测
	if (pos < 1 || S[0] < T[0]+pos)
	{
		return 0;
	}
	while (i <= S[0] && j <= T[0]) /* 若i小于S的长度并且j小于T的长度时，循环继续 */
	{
		if (S[i] == T[j]) 	/* 两字母相等则继续 */
      	{
      		//初始赋值1，匹配+1，比真实多一位，可以配合用于判断超界
			++i;
         	++j; 
      	} 
      	else 				/* 指针后退重新开始匹配 */
      	{  
         	i = i-j+2;		/* i退回到上次匹配首位的下一位 */
         	j = 1; 			/* j退回到子串T的首位 */
      	}      
	}
	//初始赋值1，最后比匹配多一位
	if (j > T[0])
	{
		return i-T[0];
	}
	else 
	{
		return 0;
	}
}


/*  T为非空串。若主串S中第pos个字符之后存在与T相等的子串， */
/*  则返回第一个这样的子串在S中的位置，否则返回0 */
int strSearchSubStrIndex2(String S, String T, int pos) 
{
	int n,m,i;
	String sub;
	//下标超界检测
	if (pos < 1 || S[0] < T[0]+pos)
	{
		return 0;
	}
	n = strLength(S);	/* 得到主串S的长度 */
	m = strLength(T);	/* 得到子串T的长度 */
	i = pos;
	while (i <= n-m+1) 
	{
		strCutOut(sub, S, i, m);	/* 取主串中第i个位置长度与T相等的子串给sub */
		if (strCompare(sub,T) != 0)    /* 如果两串不相等 */
		{
			++i;
		}
		else 				/* 如果两串相等 */
		{
			return i;		/* 则返回i值 */
		}
	}
	return 0;	/* 若无子串与T相等，返回0 */
}


/*  初始条件: 串S和T存在,1≤pos≤StrLength(S)+1 */
/*  操作结果: 在串S的第pos个字符之前插入串T。完全插入返回TRUE,部分插入返回FALSE */
StrStatus strInsert(String S,int pos,String T)
{ 
	int i;
	if(pos<1 || pos>S[0]+1)
	{
		return ERROR;
	}
	if( S[0] + T[0] <= STR_MAXSIZE)
	{ /*  完全插入 */
		//后移
		////他后移的距离包括要插入的副串位置，后面副串赋值可以覆盖
		////这个是加着后移，前对齐
		for(i=S[0]; i>=pos; i--)
		{
			S[i+T[0]]=S[i];
		}
		//插入
		for(i=pos; i<pos+T[0]; i++)
		{
			S[i]=T[i-pos+1];
		}
		//修改长度
		S[0]=S[0]+T[0];
		return TRUE;
	}
	else
	{ /*  部分插入 */
		//后移
		////他后移的距离包括要插入的副串位置，后面副串赋值可以覆盖
		////这个是减着后移，后对齐
		for(i=STR_MAXSIZE; i<=pos; i--)
		{
			S[i]=S[i-T[0]];
		}
		//插入
		////覆盖多移动的位置
		for(i=pos; i<pos+T[0]; i++)
		{
			S[i]=T[i-pos+1];
		}
		//修改长度
		S[0]=STR_MAXSIZE;
		return FALSE;
	}
}

/*  初始条件: 串S存在,1≤pos≤StrLength(S)-len+1 */
/*  操作结果: 从串S中删除第pos个字符起长度为len的子串 */
StrStatus strDelete(String S,int pos,int len)
{ 
	int i;
	if(pos<1 || pos>S[0]-len+1 || len<0)
	{
		return ERROR;
	}
	//前移
	for(i=pos+len; i<=S[0]; i++)
	{
		S[i-len] = S[i];
	}
	S[0]- = len;
	return OK;
}

/*  初始条件: 串S,T和V存在,T是非空串（此函数与串的存储结构无关） */
/*  操作结果: 用V替换主串S中出现的所有与T相等的不重叠的子串 */
StrStatus Replace(String S,String T,String V)
{ 
	int i=1; /*  从串S的第一个字符起查找串T */
	if(strEmpty(T)) /*  T是空串 */
	{
		return ERROR;
	}
	do
	{
		i= strSearchSubStrIndex(S,T,i); 	/*  结果i为从上一个i之后找到的子串T的位置 */
		if(i) 								/*  串S中存在串T */
		{
			strDelete(S,i,strLength(T)); 	/*  删除该串T */
			strInsert(S,i,V);  				/*  在原串T的位置插入串V */
			//重头找也是可以的
			i+=strLength(V);  				/*  在插入的串V后面继续查找串T */
		}
	}while(i);
	return OK;
}




/**************************************************************************************************
* 函数:                                   KMP
* 说明: 
* 返回:  
* 作者:  日南方  10/27/2020
**************************************************************************************************/
/* 通过计算返回子串T的next数组。 */
void get_next(String T, int *next) 
{
	int i,j;
  	i=1;
  	j=0;
  	next[1]=0;
  	while (i<T[0])  /* 此处T[0]表示串T的长度 */
 	{
    	if(j==0 || T[i]== T[j]) 	/* T[i]表示后缀的单个字符，T[j]表示前缀的单个字符 */
		{
      		++i;  
			++j;  
			next[i] = j;
    	} 
		else 
			j= next[j];	/* 若字符不相同，则j值回溯 */
  	}
}

/* 返回子串T在主串S中第pos个字符之后的位置。若不存在，则函数返回值为0。 */
/*  T非空，1≤pos≤StrLength(S)。 */
int Index_KMP(String S, String T, int pos) 
{
	int i = pos;		/* i用于主串S中当前位置下标值，若pos不为1，则从pos位置开始匹配 */
	int j = 1;			/* j用于子串T中当前位置下标值 */
	int next[255];		/* 定义一next数组 */
	get_next(T, next);	/* 对串T作分析，得到next数组 */
	while (i <= S[0] && j <= T[0]) /* 若i小于S的长度并且j小于T的长度时，循环继续 */
	{
		if (j==0 || S[i] == T[j]) 	/* 两字母相等则继续，与朴素算法增加了j=0判断 */
      	{
         	++i;
         	++j; 
      	} 
      	else 			/* 指针后退重新开始匹配 */
      	 	j = next[j];/* j退回合适的位置，i值不变 */
	}
	if (j > T[0]) 
		return i-T[0];
	else 
		return 0;
}

/* 求模式串T的next函数修正值并存入数组nextval */
void get_nextval(String T, int *nextval) 
{
  	int i,j;
  	i=1;
  	j=0;
  	nextval[1]=0;
  	while (i<T[0])  /* 此处T[0]表示串T的长度 */
 	{
    	if(j==0 || T[i]== T[j]) 	/* T[i]表示后缀的单个字符，T[j]表示前缀的单个字符 */
		{
      		++i;  
			++j;  
			if (T[i]!=T[j])      /* 若当前字符与前缀字符不同 */
				nextval[i] = j;	/* 则当前的j为nextval在i位置的值 */
      		else 
				nextval[i] = nextval[j];	/* 如果与前缀字符相同，则将前缀字符的 */
											/* nextval值赋值给nextval在i位置的值 */
    	} 
		else 
			j= nextval[j];			/* 若字符不相同，则j值回溯 */
  	}
}

int Index_KMP1(String S, String T, int pos) 
{
	int i = pos;		/* i用于主串S中当前位置下标值，若pos不为1，则从pos位置开始匹配 */
	int j = 1;			/* j用于子串T中当前位置下标值 */
	int next[255];		/* 定义一next数组 */
	get_nextval(T, next);	/* 对串T作分析，得到next数组 */
	while (i <= S[0] && j <= T[0]) /* 若i小于S的长度并且j小于T的长度时，循环继续 */
	{
		if (j==0 || S[i] == T[j]) 	/* 两字母相等则继续，与朴素算法增加了j=0判断 */
      	{
         	++i;
         	++j; 
      	} 
      	else 			/* 指针后退重新开始匹配 */
      	 	j = next[j];/* j退回合适的位置，i值不变 */
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
	printf("请输入串s1: ");
	
	k=StrAssign(s1,"abcd");
	if(!k)
	{
		printf("串长超过MAXSIZE(=%d)\n",MAXSIZE);
		exit(0);
	}
	printf("串长为%d 串空否？%d(1:是 0:否)\n",StrLength(s1),StrEmpty(s1));
	StrCopy(s2,s1);
	printf("拷贝s1生成的串为: ");
	StrPrint(s2);
	printf("请输入串s2: ");
	
	k=StrAssign(s2,"efghijk");
	if(!k)
	{
		printf("串长超过MAXSIZE(%d)\n",MAXSIZE);
		exit(0);
	}
	i=StrCompare(s1,s2);
	if(i<0)
		s='<';
	else if(i==0)
		s='=';
	else
		s='>';
	printf("串s1%c串s2\n",s);
	k=Concat(t,s1,s2);
	printf("串s1联接串s2得到的串t为: ");
	StrPrint(t);
	if(k==FALSE)
		printf("串t有截断\n");
	ClearString(s1);
	printf("清为空串后,串s1为: ");
	StrPrint(s1);
	printf("串长为%d 串空否？%d(1:是 0:否)\n",StrLength(s1),StrEmpty(s1));
	printf("求串t的子串,请输入子串的起始位置,子串长度: ");

	i=2;
	j=3;
	printf("%d,%d \n",i,j);

	k=SubString(s2,t,i,j);
	if(k)
	{
		printf("子串s2为: ");
		StrPrint(s2);
	}
	printf("从串t的第pos个字符起,删除len个字符，请输入pos,len: ");
	
	i=4;
	j=2;
	printf("%d,%d \n",i,j);


	StrDelete(t,i,j);
	printf("删除后的串t为: ");
	StrPrint(t);
	i=StrLength(s2)/2;
	StrInsert(s2,i,t);
	printf("在串s2的第%d个字符之前插入串t后,串s2为:\n",i);
	StrPrint(s2);
	i=Index(s2,t,1);
	printf("s2的第%d个字母起和t第一次匹配\n",i);
	SubString(t,s2,1,1);
	printf("串t为：");
	StrPrint(t);
	Concat(s1,t,t);
	printf("串s1为：");
	StrPrint(s1);
	Replace(s2,t,s1);
	printf("用串s1取代串s2中和串t相同的不重叠的串后,串s2为: ");
	StrPrint(s2);


	return 0;
}
#endif

