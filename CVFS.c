#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
//#include<iostream>
//#include<io.h>

#define MAXINODE 50
#define READ 1
#define WRITE 2
#define MAXFILESIZE 2048
#define REGULAR 1
#define SPECIAL 2

#define START 0
#define CURRENT 1
#define END 2

typedef struct superblock
{
    int TotalInodes;
    int FreeInode;
}SUPERBLOCK, *PSUPERBLOCK;

typedef struct inode 
{
    char FileName[50];
    int InodeNumber;
    int FileSize;
    int FileActualSize;
    int FileType;
    char *Buffer;
    int LinkCount;
    int ReferenceCount;
    int permission;//1 23
    struct inode *next;
}INODE, *PINODE, **PPINODE;

typedef struct filetable
{
    int readoffset;
    int writeoffset;
    int count;
    int mode;//1 2 3 
    PINODE ptrinode;
}FILETABLE, *PFILETABLE;

typedef struct ufdt
{
    PFILETABLE prtfiletable;
}UFDT;

UFDT UFDTArr[50];
SUPERBLOCK SUPERBLOCKobj;
PINODE head = NULL;

void man(char *name)
{
    if(name==NULL)return;

    if(strcmp(name,"create")==0)
    {
        printf("Description : Used to create new regular file\n");
        printf("Usage : create File_name Permission\n");
    }
    else if(strcmp(name,"read")==0)
    {
        printf("Description : Used to read data from regular file\n");
        printf("Usage : read File_name No_Of_Bytes_ To_Read\n");
    }
    else if(strcmp(name,"write")==0)
    {
        printf("Description : Used to wrtite into regular file\n");
        printf("Usage : write File_name\n Ater this enter the data that we want to write\n");
    }
    else if(strcmp(name,"ls")==0)
    {
        printf("Description : Used to list all information of file\n");
        printf("Usage : ls\n");
    }
    else if(strcmp(name,"stat")==0)
    {
        printf("Description : Used to display information of file\n");
        printf("Usage : stat File_name\n");
    }
    else if(strcmp(name,"fstat")==0)
    {
        printf("Description : Used to display information file\n");
        printf("Usage : stat File_Descriptor\n");
    }
    else if(strcmp(name,"truncate")==0)
    {
        printf("Description : Used to remove data from file\n");
        printf("Usage : truncate File_name\n");
    }
    else if(strcmp(name,"open")==0)
    {
        printf("Description : Used to open existing file\n");
        printf("Usage : open File_name mode\n");
    }
    else if(strcmp(name,"close")==0)
    {
        printf("Description : Used to close opened file\n");
        printf("Usage : close File_name\n");
    }
    else if(strcmp(name,"closeall")==0)
    {
        printf("Description : Used to close all opened file\n");
        printf("Usage : closeall\n");
    }
    else if(strcmp(name,"lseek")==0)
    {
        printf("Description : Used to change file offset\n");
        printf("Usage : lseek File_Name ChangeInOffset StartPoint\n");
    }
    else if(strcmp(name,"rm")==0)
    {
        printf("Description : Used to delete the file\n");
        printf("Usage : rm File_Name\n");
    }
    else 
    {
        printf("ERROR : No manual entry available.\n");
    }
}

void DisplayHelp()
{
    printf("ls : To List out all files\n");
    printf("clear : To clear console\n");
    printf("open : To open the file\n");
    printf("close : To close the file\n");
    printf("closeall : To close all opened files");
    printf("read : To Read the contents from file\n");
    printf("write : To Write contents into file\n");
    printf("exit : To Terminate file system\n");
    printf("stat : To Display Information of file using name\n");
    printf("fstat : To Display information of file using file descripter");
    printf("truncate : To Remove all data from file\n");
    printf("rm : To Delete the file\n");
}

int GetFDFromName(char *name)
{
    int i=0;

    while(i<50)
    {
        if(UFDTArr[i].prtfiletable != NULL)
            if(strcmp((UFDTArr[i].prtfiletable->ptrinode->FileName),name)==0)
                    break;
        i++;
    }

    if(i==50)
    {
        return -1;
    }
    else
    {
        return i;
    }
}

PINODE Get_Inode(char *name)
{
    PINODE temp=head;
    int i=0;

    if(name==NULL)
        return NULL;

    while(temp!=NULL)
    {
        if(strcmp(name,temp->FileName)==0)
            break;
        temp=temp->next;
    }
    return temp;
}

void CreateDILB()
{
    int i=1;
    PINODE newn =NULL;
    PINODE temp =head;

    while(i<=MAXINODE)
    {
        newn=(PINODE)malloc(sizeof(INODE));

        newn->LinkCount=0;
        newn->ReferenceCount=0;
        newn->FileType=0;
        newn->FileSize=0;

        newn->Buffer=NULL;
        newn->next=NULL;

        newn->InodeNumber=i;

        if(temp==NULL)
        {
            head=newn;
            temp=head;
        }
        else
        {
            temp->next=newn;
            temp=temp->next;
        }
        i++;
    }
    printf("DILB Created Successfully\n");
}

void InitialiseSuperBlock()
{
    int i=0;
    while(i<MAXINODE)
    {
        UFDTArr[i].prtfiletable=NULL;
        i++;
    }
    SUPERBLOCKobj.TotalInodes=MAXINODE;
    SUPERBLOCKobj.FreeInode=MAXINODE;
}

int CreateFile(char *name,int permission)
{
    int i=0;
    PINODE temp=head;

    if((name==NULL) || (permission==0) || (permission>3))
        return -1;

    if(SUPERBLOCKobj.FreeInode==0)
        return -2;
    (SUPERBLOCKobj.FreeInode)--;

    if(Get_Inode(name)!=NULL)
        return -3;

    while(temp!=NULL)
    {
        if(temp->FileType==0)
            break;
        temp=temp->next;
    }

    while(i<50)
    {
        if(UFDTArr[i].prtfiletable==NULL)
            break;
        i++;
    }

    UFDTArr[i].prtfiletable->count=1;
    UFDTArr[i].prtfiletable->mode=permission;
    UFDTArr[i].prtfiletable->readoffset=0;
    UFDTArr[i].prtfiletable->writeoffset=0;

    UFDTArr[i].prtfiletable->ptrinode=temp;

    strcpy(UFDTArr[i].prtfiletable->ptrinode->FileName,name);
    UFDTArr[i].prtfiletable->ptrinode->FileType=REGULAR;
    UFDTArr[i].prtfiletable->ptrinode->ReferenceCount=1;
    UFDTArr[i].prtfiletable->ptrinode->LinkCount=1;
    UFDTArr[i].prtfiletable->ptrinode->FileSize=MAXFILESIZE;
    UFDTArr[i].prtfiletable->ptrinode->FileActualSize=0;
    UFDTArr[i].prtfiletable->ptrinode->permission=permission;
    UFDTArr[i].prtfiletable->ptrinode->Buffer=(char *)malloc(MAXFILESIZE);

    return i;
}

//rm_File ("Demo.txt")
int rm_File(char * name)
{
    int fd=0;

    fd=GetFDFromName(name);
    if(fd==-1)
        return -1;

    (UFDTArr[fd].prtfiletable->ptrinode->LinkCount)--;

    if(UFDTArr[fd].prtfiletable->ptrinode->LinkCount==0)
    {
        UFDTArr[fd].prtfiletable->ptrinode->FileType=0;
        //free(UFDTArr[fd].prtfiletable->ptrinode->Buffer);
        free(UFDTArr[fd].prtfiletable);
    }
    UFDTArr[fd].prtfiletable=NULL;
    (SUPERBLOCKobj.FreeInode)++;
}

int ReadFile(int fd,char *arr,int isize)
{
    int read_size=0;

    if(UFDTArr[fd].prtfiletable=NULL)
        return -1;

    if(UFDTArr[fd].prtfiletable->mode!= READ && UFDTArr[fd].prtfiletable->mode!=READ+WRITE)
        return -2;

    if(UFDTArr[fd].prtfiletable->ptrinode->permission != READ && UFDTArr[fd].prtfiletable->ptrinode->permission!=READ+WRITE)
        return -2;

    if(UFDTArr[fd].prtfiletable->readoffset==UFDTArr[fd].prtfiletable->ptrinode->FileActualSize)
        return-3;

    if(UFDTArr[fd].prtfiletable->ptrinode->FileType!=REGULAR)
        return -4;

    read_size=(UFDTArr[fd].prtfiletable->ptrinode->FileActualSize)-(UFDTArr[fd].prtfiletable->readoffset);
    if(read_size<isize)
    {
        strcpy(arr,(UFDTArr[fd].prtfiletable->ptrinode->Buffer)+(UFDTArr[fd].prtfiletable->readoffset),read_size);
        UFDTArr[fd].prtfiletable->readoffset=UFDTArr[fd].prtfiletable->readoffset+read_size;
    }
    else
    {
        strcpy(arr,(UFDTArr[fd].prtfiletable->ptrinode->Buffer)+(UFDTArr[fd].prtfiletable->readoffset),isize);
        (UFDTArr[fd].prtfiletable->readoffset)=(UFDTArr[fd].prtfiletable->readoffset)+isize;
    }
    return isize;
}

int WriteFile(int fd,char *arr,int isize)
{
    if(((UFDTArr[fd].prtfiletable->mode)!=WRITE)&&((UFDTArr[fd].prtfiletable->mode)!=READ+WRITE))
        return -1;

    if(((UFDTArr[fd].prtfiletable->ptrinode->permission)!=WRITE)&7 ((UFDTArr[fd].prtfiletable->ptrinode->permission)!=READ+WRITE))
        return -1;

    if((UFDTArr[fd].prtfiletable->writeoffset)==MAXFILESIZE)
        return -2;

    if((UFDTArr[fd].prtfiletable->ptrinode->FileType)!=REGULAR)
        return -3;

    strcmp((UFDTArr[fd].prtfiletable->ptrinode->Buffer)+(UFDTArr[fd].prtfiletable->writeoffset),arr,isize);

    (UFDTArr[fd].prtfiletable->ptrinode->FileActualSize)=(UFDTArr[fd].prtfiletable->writeoffset)+isize;

    return isize;
}

int OpenFile(char *name,int mode)
{
    int i=0;
    PINODE temp=NULL;

    if(name==NULL || mode<=0)
        return -1;

    temp Get_Inode(name);
    if(temp==NULL)
        return -2;

    if(temp->permission<mode)
        return -3;

    while(i<50)
    {
        if(UFDTArr[i].prtfiletable==NULL)
            break;
        i++;
    }
    UFDTArr[i].prtfiletable=(PFILETABLE)malloc(sizeof(FILETABLE));
    if(UFDTArr[i].prtfiletable==NULL)
        return -1;
    UFDTArr[i].prtfiletable->count=1;
    UFDTArr[i].prtfiletable->mode=mode;
    if(mode==READ+WRITE)
    {
        UFDTArr[i].prtfiletable->readoffset=0;
        UFDTArr[i].prtfiletable->writeoffset=0;
    }
    else if(mode==READ)
    {
        UFDTArr[i].prtfiletable->readoffset=0;
    }
    else if(mode==WRITE)
    {
        UFDTArr[i].prtfiletable->writeoffset=0;
    }
    UFDTArr[i].prtfiletable->ptrinode=temp;
    (UFDTArr[i].prtfiletable->ptrinode->ReferenceCount)++;
    return i;
}

void CloseFileByName(int fd)
{
    UFDTArr[fd].prtfiletable->readoffset=0;
    UFDTArr[fd].prtfiletable->writeoffset=0;
    (UFDTArr[fd].prtfiletable->ptrinode->ReferenceCount)--;
}

int CloseFileByName(char *name)
{
    int i=0;
    i=GetFDFromName(name);
    if(i==-1)
        return -1;

    UFDTArr[i].prtfiletable->readoffset=0;
    UFDTArr[i].prtfiletable->writeoffset=0;
    (UFDTArr[i].prtfiletable->ptrinode->ReferenceCount)--;

    return 0;
}

void CloseAllFile()
{
    int i=0;
    while(i<50)
    {
        if(UFDTArr[i].prtfiletable!=NULL)
        {
            UFDTArr[i].prtfiletable->readoffset=0;
            UFDTArr[i].prtfiletable->writeoffset=0;
            (UFDTArr[i].prtfiletable->ptrinode->ReferenceCount)--;
            break;
        }
        i++;
    }
}

int LseelFile(int fd,int size,int from)
{
    if((fd<0) || (from>2))
        return -1;
    if(UFDTArr[fd].prtfiletable==NULL)
    return -1;
    
    if((UFDTArr[fd].prtfiletable->mode==READ)||(UFDTArr[fd].prtfiletable->mode==READ+WRITE))
    {
        if(from==CURRENT)
        {
            if(((UFDTArr[fd].prtfiletable->readoffset)+size)>UFDTArr[fd].prtfiletable->ptrinode->FileActualSize)
                return -1;
            if(((UFDTArr[fd].prtfiletable->readoffset)+size)<0)
                return -1;
            (UFDTArr[fd].prtfiletable->readoffset)=(UFDTArr[fd].prtfiletable->readoffset)+size;
        }
        else if(from==START)
        {
            if(size>(UFDTArr[fd].prtfiletable->ptrinode->FileActualSize))
                return -1;
            (UFDTArr[fd].prtfiletable->readoffset)=size;
        }
        else if(from==END)
        {
            if((UFDTArr[fd].prtfiletable->ptrinode->FileActualSize)+size>MAXFILESIZE)
                return -1;
            if(((UFDTArr[fd].prtfiletable->readoffset)+size)<0)
                return -1;
            (UFDTArr[fd].prtfiletable->readoffset)=(UFDTArr[fd].prtfiletable->ptrinode->FileActualSize)+size;
        }
    }
    else if(UFDTArr[fd].prtfiletable->mode==WRITE)
    {
        if(from==CURRENT)
        {
            if(((UFDTArr[fd].prtfiletable->writeoffset)+size)>MAXFILESIZE)
                return -1;
            if(((UFDTArr[fd].prtfiletable->writeoffset)+size)<0)
                return -1;
            if(((UFDTArr[fd].prtfiletable->writeoffset)+size)>(UFDTArr[fd].prtfiletable->ptrinode->FileActualSize))
            (UFDTArr[fd].prtfiletable->ptrinode->FileActualSize)=(UFDTArr[fd].prtfiletable->writeoffset)+size;
            (UFDTArr[fd].prtfiletable->writeoffset)=(UFDTArr[fd].prtfiletable->writeoffset)+size;
        }
        else if(from == START)
        {
            if(size>MAXFILESIZE)
            return -1;
            if(size<0)
            return -1;
            if(size>(UFDTArr[fd].prtfiletable->ptrinode->FileActualSize))
            (UFDTArr[fd].prtfiletable->ptrinode->FileActualSize)=size;
            (UFDTArr[fd].prtfiletable->writeoffset)=size;
        }
        else if(from==END)
        {
            if((UFDTArr[fd].prtfiletable->ptrinode->FileActualSize)+size>MAXFILESIZE)
            return -1;
            if(((UFDTArr[fd].prtfiletable->writeoffset)+size)<0)
            return -1;
            (UFDTArr[fd].prtfiletable->writeoffset)=(UFDTArr[fd].prtfiletable->ptrinode->FileActualSize)+size;
        }
    }
}

void ls_file()
{
    int i=0;
    PINODE temp=head;

    if(SUPERBLOCKobj.FreeInode==MAXINODE)
    {
        printf("Error : There are no files\n");
        return;
    }

    printf("\nFile Name\tInode number\tFile size\tLink count\n");
    printf("----------------------------------------------------------------\n");
    while(temp!= NULL)
    {
        if(temp->FileType!=0)
        {
            printf("%s\t\t%d\t\t%d\t\t%d\n",temp->FileName,temp->InodeNumber,temp->FileActualSize,temp->LinkCount);
        }
        temp=temp->next;
    }
    printf("----------------------------------------------------------------\n");
}

int fstat_file(int fd)
{
    PINODE temp=head;
    int i=0;

    if(fd<0)
    return -1;
    if(UFDTArr[fd].prtfiletable==NULL)
    return -2;

    temp=UFDTArr[fd].prtfiletable->ptrinode;

    printf("\n---------------Statistical Information about file-----------------\n");
    printf("File name : %s\n",temp->FileName);
    printf("Inode Number %d\n",temp->InodeNumber);
    printf("File size : %d\n",temp->FileSize);
    printf("Actual File size : %d\n",temp->FileActualSize);
    printf("Link count : %d\n",temp->LinkCount);
    printf("Reference count : %d\n",temp->ReferenceCount);

    if(temp->permission==1)
        printf("File Permission : Read only\n");
    else if(temp->permission==2)
        printf("File Permission : Write\n");
    else if(temp->permission==3)
        printf("File Permission : Read & Write\n");
    printf("----------------------------------------------------------------\n");

    return 0;
}

int stat_file(char *name)
{
    PINODE temp=head;
    int i=0;

    if(name==NULL)
    return -1;

    while(temp!=NULL)
    {
        if(strcmp(name,temp->FileName)==0)
            break;
        temp=temp->next;
    }

    if(temp==NULL)
    return -2;

    printf("\n---------------Statistical Information about file-----------------\n");
    printf("File name : %s\n",temp->FileName);
    printf("Inode Number %d\n",temp->InodeNumber);
    printf("File size : %d\n",temp->FileSize);
    printf("Actual File size : %d\n",temp->FileActualSize);
    printf("Link count : %d\n",temp->LinkCount);
    printf("Reference count : %d\n",temp->ReferenceCount);

    if(temp->permission==1)
        printf("File Permission : Read only\n");
    else if(temp->permission==2)
        printf("File Permission : Write\n");
    else if(temp->permission==3)
        printf("File Permission : Read & Write\n");
    printf("----------------------------------------------------------------\n");

    return 0;
}

int truncate_File(char *name)
{
    int fd=GetFDFromName(name);
    if(fd==-1)
    return -1;

    memset(UFDTArr[fd].prtfiletable->ptrinode->Buffer,0,1024);
    UFDTArr[fd].prtfiletable->readoffset=0;
    UFDTArr[fd].prtfiletable->writeoffset=0;
    UFDTArr[fd].prtfiletable->ptrinode->FileActualSize=0
}

int main()
{
    char *prt=NULL;
    int ret=0,fd=0,count=0;
    char command[4][80],str[80],arr[1024];

    InitialiseSuperBlock();
    CreateDILB();

    while(1)
    {
        fflush(stdin);
        strcpy(str,"");

        printf("\nMarvellous VFS : >");

        fgets(str,80,stdin);//scanf("%[^'\n']s",str);

        count=sscanf(str,"%s %s %s %s",command[0],command[1],command[2],command[3]);

        if(count==1)
        {
            if(strcmp(command[0],"ls")==0)
            {
                ls_file();
            }
            else if(strcmp(command[0],"closeall")==0)
            {
                CloseAllFile();
                printf("All files closed successfully\n");
                continue;
            }
            else if(strcmp(command[0],"clear")==0)
            {
                system("cls");
                continue;
            }
            else if(strcmp(command[0],"help")==0)
            {
                DisplayHelp();
                continue;
            }
            else if(strcmp(command[0],"exit")==0)
            {
                printf("Terminating the Marvellous Virtual File System\n");
                break;
            }
            else
            {
                printf("\nERROR : Command not found !!!\n");
                continue;
            }
            
        }
        else if(count==2)
            {
                if(strcmp(command[0],"stat")==0)
                {
                    ret=stat_file(command[1]);
                    if(ret ==-1)
                        printf("ERROR : Incorrect parameters\n");
                    if(ret==-2)
                        printf("ERROR : There is no such file\n");
                    continue;
                }
                else if(strcmp(command[0],"ftat")==0)
                {
                    ret=ftat_file(atoi(command[1]));
                    if(ret ==-1)
                        printf("ERROR : Incorrect parameters\n");
                    if(ret==-2)
                        printf("ERROR : There is no such file\n");
                    continue;
                }
                else if(strcmp(command[0],"close")==0)
                {
                    ret=CloseFileByName(command[1]);
                    if(ret==-1)
                    printf("ERROR : There is no such file\n");
                    continue;
                }
                else if(strcmp(command[0],"rm")==0)
                {
                    ret=rm_File(command[1]);
                    if(ret==-1)
                    printf("ERROR : There is no such file\n");
                    continue;
                }
                else if(strcmp(command[0],"man")==0)
                {
                    man(command[1]);
                }
                else if(strcmp(command[0],"write")==0)
                {
                    fd=GetFDFromName(command[1]);
                    if(fd==-1)
                    {
                        printf("Error : Incorrect paramater\n");
                        continue;
                    }
                    printf("Enter the data : \n");
                    scanf("%[^\n]",arr);

                    ret=strlen(arr);
                    if(ret==0)
                    {
                        printf("Error : Incorrect paramater\n");
                        continue; 
                    }
                    ret =WriteFile(fd,arr,ret);
                    if(ret==-1)
                        printf("Permission denied\n");
                    if(ret==-2)
                        printf("There is no sufficient memory to write\n");
                    if(ret==-3)
                        printf("ERROR : It is not regular file\n");
                }
                else if(strcmp(command[0],"truncare")==0)
                {
                    ret=truncate_File(command[1]);
                    if(ret==-1)
                        printf("Error : Incorrect parameter\n");
                }
                else 
                {
                    printf("\nERROR : Command not found !!\n!");
                    continue;
                }
            }
            else if(count==3)
            {
                if(strcmp(command[0],"create")==0)
                {
                    ret=CreateFile(command[1],atoi(command[2]));
                    if(ret>=0)
                        printf("File is successfully created with file descriptor : %d\n",ret);
                    if(ret==-1)
                        printf("Error : Incorrect parameters\n");
                }
            }
    }
}
