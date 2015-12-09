#include "Windivert_Packet_System.h"

void Windivert_Packet_System::Windivert_Open_UDP()
{
	INT16 priority = 0;
	cout << " �ð� �Է� " << endl;
	cin >> input_time;

	handle = WinDivertOpen("udp and outbound", WINDIVERT_LAYER_NETWORK, priority, 0); // ��Ŷ ����. ��� ��Ŷ�� �ٹ޾ƿ;���.
	if (handle == INVALID_HANDLE_VALUE) // HANDLE ���� �����϶�
	{
		if (GetLastError() == ERROR_INVALID_PARAMETER)
		{
			fprintf(stderr, "error: filter syntax error\n");
			exit(EXIT_FAILURE);
		}
		fprintf(stderr, "error: failed to open the WinDivert device (%d)\n",
			GetLastError());
		exit(EXIT_FAILURE);
	}



}

void Windivert_Packet_System::ReceiveUdp_Packet()
{
	unsigned char packet[MAXBUF];
	WINDIVERT_ADDRESS recv_addr;
	UINT packet_len;

	while (TRUE)
	{
		// Read a matching packet.
		if (!WinDivertRecv(handle, packet, sizeof(packet), &recv_addr, // ��Ŷ���� �޾ƿ�, ���� �� �޾ƿ�
			&packet_len))
		{
			fprintf(stderr, "warning: failed to read packet\n");
			continue;
		}

		// Print info about the matching packet.
		WinDivertHelperParsePacket(packet, packet_len, NULL, // �����ϱ� ���� ��Ŷ���� �Ľ��Ѵ�.
			NULL, NULL, NULL, NULL,
			NULL, NULL, NULL);


		SENDSAVEPACKET UDP_temp; //

		memcpy(&(UDP_temp.buff), &packet, packet_len); // UDP ��Ŷ ����
		memcpy(&(UDP_temp.send_addr), &recv_addr, sizeof(WINDIVERT_ADDRESS)); //�ּ� ����
		UDP_temp.len = packet_len;
		UDP_temp.receive_packet_time = chrono::system_clock::now(); // �ð��ޱ�




	}

}
