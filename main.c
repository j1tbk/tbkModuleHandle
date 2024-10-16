#include <stdio.h>
//#include <windows.h>

extern long long* myFunc();
extern long long* getPEB();
extern long long* getLDR(long long* pPEB);
extern long long* getDTE(long long* pLDR);
extern long long* getDteName(long long* pDTE);
extern long long* getDteBase(long long* pDTE);
extern long long* getNextDte(long long* pDTE);


short isWstrEqual(wchar_t* wstr1, wchar_t* wstr2) {
	wchar_t wstr1_buffer[80];
	wchar_t wstr2_buffer[80];
	wcscpy_s(wstr1_buffer, 40, wstr1);
	wcscpy_s(wstr2_buffer, 40, wstr2);

	for (int i = 0; wstr1_buffer[i] != L'\0'; i++) {
		wstr1_buffer[i] = towlower(wstr1_buffer[i]);
	}
	for (int i = 0; wstr2_buffer[i] != L'\0'; i++) {
		wstr2_buffer[i] = towlower(wstr2_buffer[i]);
	}

	return (wcscmp(wstr1_buffer, wstr2_buffer));
}


 long long* getModuleHandleReplacement(wchar_t* moduleName) {
	long long* pPeb = getPEB();
	long long* pLdr = getLDR(pPeb);
	long long* pDte = getDTE(pLdr);

	wchar_t* dteName = NULL;

	do {
		dteName = getDteName(pDte);
		if (dteName != NULL) {
			if (isWstrEqual(dteName, moduleName) == 0) {
				//printf("Found\n");
				return getDteBase(pDte);
			}
			pDte = getNextDte(pDte);
		}
		else {
			break;
		}

	} while (pDte);
}

int main(){
	wchar_t* moduleName = L"kernel32.dll";
	printf("Addr: 0x%p\n", getModuleHandleReplacement(moduleName));
	//printf("Addr: 0x%p\n", GetModuleHandleW(moduleName));
}
