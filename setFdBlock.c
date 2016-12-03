/*************************************************************************
	> File Name:    setFdBlock.c
	> Author:       vividwei
	> Mail:         353470469@qq.com
	> Created Time: 2016年12月03日 星期六 13时21分02秒
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int setNoBlock(int fd)
{
    int flags  = -1;
    int retval = -1;

    flags = fcntl(fd, F_GETFL);
    if (-1 == flags)
    {
        perror("获取状态失败!\n");

        return -1; 
    }

    flags |= O_NONBLOCK;

    retval = fcntl(fd, F_SETFL, flags);
    if (-1 == retval)
    {
        perror("设置非阻塞失败!\n");

        return -1;
    }

    return 0;
}

int closeNoBlock(int fd)
{
    int retval = -1;
    int flags  = -1;

    flags = fcntl(fd, F_GETFL);
    if (-1 == flags)
    {
        perror("获取状态失败!\n");

        return -1;
    }

    flags &= ~O_NONBLOCK;

    retval = fcntl(fd, F_SETFL, flags);
    if (-1 == retval)
    {
        perror("关闭描述符的非阻塞状态失败!\n");

        return -1;
    }

    return 0;
}
