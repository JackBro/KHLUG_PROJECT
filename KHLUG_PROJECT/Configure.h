#pragma once

#pragma comment(lib, "Ws2_32.lib")
#pragma comment(lib, "IPHLPAPI.lib")
#pragma comment(lib, "windivert.lib")
#pragma comment(lib, "wpcap.lib")

#include <stdio.h>
#include <stdlib.h>

#include <WinSock2.h>
#include <iphlpapi.h>
#include <Windows.h>
#include <conio.h>

#include <iostream>
#include <string>
#include <vector>
#include <thread> // c++ 11 �����带 ���� ���� �߰��� ���.

// ���� �ҽ��� pcap ���̺귯���� windivert ���̺귯�� ��Ŭ��� 
// winpcap�� windivert�� ���̴� ���� ��Ŷ�̳� ���� ��Ŷ�� ���� ç�� �ִ��� �ƴ� ���⸸ �ϴ��� ����
// windiver �Լ��� ����ҷ��� ������ ���� �Ѿߵǰ� �̻��ϰ� ������� �õ��ϸ� ��Ŷ ��ü�� �ȿ��� ( �Ƹ� ����̹� ���� �����ε� )
#include <pcap.h>
#include <windivert.h>