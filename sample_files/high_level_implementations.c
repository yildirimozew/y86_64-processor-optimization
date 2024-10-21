long binary_search_it(long *begin, long *end, long value) {
    long *mid;
    long *initial_begin = begin;
    while (begin < end) {
        mid = begin + ((end - begin) / 2);
        if (*mid == value) {
            return mid - initial_begin + 1;
        } else if (*mid < value) {
            begin = mid + 1;
        } else {
            end = mid;
        }
    }
    return -1;
}

long binary_search_rec(long *begin, long *end, long value) {
    long *mid = begin + ((end - begin) >> 1);
    long tmp;
    if (begin >= end) {
        return -1;
    } else if (*mid == value) {
        return mid - begin + 1;
    } else if (*mid < value) {
        tmp = binary_search_rec(mid + 1, end, value);
        if(tmp != -1) {
            return tmp + (mid - begin) + 1;
        } else {
            return tmp;
        }
    } else {
        return binary_search_rec(begin, mid, value);
    }
}
rbx = mid 
rcx = tmp

void merge(long *begin1, long *end1, long *begin2, long *end2, long *begin3) {
    while(begin1 < end1 && begin2 < end2) {
        if (*begin1 < *begin2) {
            *begin3++ = *begin1++;
        } else {
            *begin3++ = *begin2++;
        }
    }
    while (begin1 < end1) {
        *begin3++ = *begin1++;
    }
    while (begin2 < end2) {
        *begin3++ = *begin2++;
    }
}
rdi:begin1
rsi:end1
rdx:begin2 
rcx:end2
r8:begin3
r11:*begin1
r12:*begin2
r10:8

void switch8(long *begin1, long *begin2, long length) {
    while(length--) {
        switch(*begin1 % 8) {
            case 0:
                *begin2 = *begin1+1;
                break;
            case 1:
                *begin2 = *begin1*5;
                break;
            case 2:
                *begin2 = *begin1/2;
                break;
            case 3:
                *begin2 = *begin1%3;
                break;
            case 4:
                *begin2 = *begin1-7;
                break;
            case 5:
                *begin2 = 331;
                break;
            case 6:
                *begin2 = *begin1+10;
            case 7:
            default:
                *begin2 = *begin1/3;
            *begin2 += 16;
        }
    }
}
implement jtab in pipe
look at how normal jmp is implemented in pipe
loop unrolling denilen şey
implement cases using jtab and a table like the one in jtab test
rdi:begin1
rsi:begin2
rdx:length
rcx:8






    rrmovq %r8, %r9
    andq %r9, %r9
    je case0
    rrmovq %r8, %r9
    irmovq $1, %r10
    subq %r10, %r9
    je case1
    rrmovq %r8, %r9
    irmovq $2, %r10
    subq %r10, %r9
    je case2
    rrmovq %r8, %r9
    irmovq $3, %r10
    subq %r10, %r9
    je case3
    rrmovq %r8, %r9
    irmovq $4, %r10
    subq %r10, %r9
    je case4
    rrmovq %r8, %r9
    irmovq $5, %r10
    subq %r10, %r9
    je case5
    rrmovq %r8, %r9
    irmovq $6, %r10
    subq %r10, %r9
    je case6
    rrmovq %r8, %r9
    irmovq $7, %r10
    subq %r10, %r9
    je case7