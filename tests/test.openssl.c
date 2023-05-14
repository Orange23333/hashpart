#include <string.h>
#include <openssl/evp.h>

/*
#define IN_CLOSED_INTERVAL(value,min,max) (min<=value&&value<=max)

typedef struct{
	char high;
	char low;
}DoubleHexChar;

char HexToChar(unsigned char value){
	if(IN_CLOSED_INTERVAL(value,0,9)){
		return value+'0';
	}else{
		return value-10+'A';
		// Do not care about out of range.
	}
}

DoubleHexChar DHexToDChar(unsigned char value){
	DoubleHexChar r;
	r.high = HexToChar((value&0xF0)>>4);
	r.low = HexToChar(value&0x0F);
	return r;
}
*/

void ViewHex(unsigned char* data, size_t size){
	size_t i;
	//DoubleHexChar r;

	for(i=0;i<size;i++){
		printf("%2X",data[i]);
	}
}

int main(){
	unsigned char data[128] = "你好，OpenSSL！";
    int data_size = strlen((char*)data);

    //初始化EVP上下文
    EVP_MD_CTX *ctx = EVP_MD_CTX_new();
    const EVP_MD *evp_md = EVP_sm3();

    //hash初始化
    EVP_DigestInit_ex(ctx, evp_md, NULL);

    //计算hash值
    EVP_DigestUpdate(ctx, data, data_size);


    //获取结果
    unsigned char out[256/8] = { 0 };
    unsigned int out_size = 0;
    EVP_DigestFinal_ex(ctx, out, &out_size);

	printf("SM3(size=%dbytes): ",out_size);
    ViewHex(out, out_size);
	putchar('\n');

    //清理上下文
    EVP_MD_CTX_free(ctx);

    //调用EVP简化接口编码
    EVP_Digest(data, data_size, out, &out_size, EVP_sm3(), NULL);

    printf("SM3(size=%dbytes): ",out_size);
    ViewHex(out, out_size);
	putchar('\n');

	return 0;
}