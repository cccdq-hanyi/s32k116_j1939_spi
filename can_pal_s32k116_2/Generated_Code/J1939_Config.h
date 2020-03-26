/*********************************************************************
 *
 *            J1939 Main Source Code
 *
 ********************************************************************/

#ifndef __J1939_Config_H
#define __J1939_Config_H

#include "J1939.H"
extern CAN_NODE   Can_Node;   //CANӲ��ѡ��


/***************************J1939 ��ַ����*****************************/
//�豸Ĭ�ϵĵ�ַ����ַ�������й涨�ģ��ο�J1939�ĸ�¼B ��ַ�ͱ�ʶ���ķ��䣩
#define J1939_STARTING_ADDRESS_1 0x01
#define J1939_STARTING_ADDRESS_2 244
#define J1939_STARTING_ADDRESS_3 247
#define J1939_STARTING_ADDRESS_4 0


/******************************J1939��������***************************/
#define J1939_RX_QUEUE_SIZE 3
//��mcu������������Ϣ��������Ϣ�ж��Ƿ��������µ���Ϣ����
#define J1939_OVERWRITE_RX_QUEUE J1939_FALSE
#define J1939_TX_QUEUE_SIZE 3
//��mcu������������Ϣ��������Ϣ�ж��Ƿ��������µ���Ϣ����
#define J1939_OVERWRITE_TX_QUEUE J1939_FALSE
//�Ƿ�ʹ����ѯģʽ������ʹ���ж�ģʽ��
#define J1939_POLL_ECAN J1939_TRUE
//�Ƿ����������˲���
#define J1939SoftwareFilterEn J1939_TRUE
/******************************J1939��ֲ���ú���************************/

#define Port_CAN_Transmit(MsgPtr) J1939_CAN_Transmit(MsgPtr)
#define Port_CAN_Receive(MsgPtr) J1939_CAN_Receive(MsgPtr)
#define Port_SetAddressFilter(Address) J1939_SetAddressFilter(Address)
/*��ʹ���ж�ģʽ����������ĺ���������ֲ*/
#if J1939_POLL_ECAN == J1939_FALSE
	#define Port_RXinterruptEnable() J1939_RXinterruptEnable()
	#define Port_RXinterruptDisable() J1939_RXinterruptDisable()
	#define Port_TXinterruptEnable() J1939_TXinterruptEnable()
	#define Port_TXinterruptDisable() J1939_TXinterruptDisable()
	#define Port_TXinterruptOk() J1939_TXinterruptOk()
	#define Port_CAN_identifier_clc()  CAN_identifier_clc()
#endif

/***************************************************************************************/

/*
*���룺
*�����
*˵��������SAE J1939Э�飬������ҪCAN�������ṩ����3���˲�����J1939Э����롣�����˲����ֱ��������£�
		1. �����˲���0��ֻ���ܹ㲥��Ϣ��PF = 240 -255����
		2. ���������˲���1��2ֻ����ȫ�ֵ�ַ��J1939_GLOBAL_ADDRESS��
        3. ���ų�������У����ı��˲���2������Ӧ�����߼���
	J1939_SetAddressFilter() �����������˲���2�ģ� ������Ҫ����PSλ��Ŀ���ַ������Ŀ���ǣ��ÿ�����
	ֻ���ܷ��͸����豸����Ϣ��
*���棺 �˲���0��1����CAN���������ã������Ӳ���˲����ò��Ǻ�����������ʹ�������˲�����#define J1939SoftwareFilterEn
*�����������������ֲ��CANӲ���˲��������ã�Ϊ��J1939Э��ջ�������Ż�������ֻ����Ӳ���˲���
*/
void J1939_SetAddressFilter(unsigned char Ps_Address)
{
	switch (Can_Node)
	{
		case  Select_CAN_NODE_1:
		{
			break;
		}
		case  Select_CAN_NODE_2:
		{
			break;
		}
		case  Select_CAN_NODE_3:
		{
			break;
		}
		case  Select_CAN_NODE_4:
		{
			break;
		}
		default  :
		{
			break;
		}
	}
}

/*
*���룺  *MsgPtr ��Э��Ҫ���͵���Ϣ��
*�����
*˵����      ������ ��MsgPtr�ṹ�帳ֵ��CAN�����Դ��Ľṹ����
		�Ƚ����뺯����MsgPtr�е�����д��CAN�Ľṹ�壬�ٵ���CAN�����ķ��ͺ���
		Ĭ��֧��4·CANӲ�����շ���������4·��ֻ��������Ӧ��Can_Node���ش�������
		������Select_CAN_NODE�����ֲ��䡣��ֱ�ӷ��أ�break����
*/
void J1939_CAN_Transmit(J1939_MESSAGE *MsgPtr)
{

	switch (Can_Node)
	{
		case  Select_CAN_NODE_1:
		{

			/*���ص�һ·CANӲ����29λID*/

			/*CANӲ���������ݳ���*/

			/*CANӲ����������*/

			/*CANӲ������RTR*/

			//CANӲ����ʼ��������

			break;
		}
		case  Select_CAN_NODE_2:
		{

			/*���صڶ�·CANӲ����29λID*/

			/*CANӲ���������ݳ���*/

			/*CANӲ����������*/

			/*CANӲ������RTR*/

			//CANӲ����ʼ��������
			break;
		}
		case  Select_CAN_NODE_3:
		{

			/*���ص���·CANӲ����29λID*/

			/*CANӲ���������ݳ���*/

			/*CANӲ����������*/

			/*CANӲ������RTR*/

			//CANӲ����ʼ��������
			break;
		}
		case  Select_CAN_NODE_4:
		{
			/*���ص���·CANӲ����29λID*/

			/*CANӲ���������ݳ���*/

			/*CANӲ����������*/

			/*CANӲ������RTR*/

			//CANӲ����ʼ��������
			break;
		}
		default  :
		{
			break;
		}
	}
}
/*
*���룺     *MsgPtr ����Ҫ������ڴ��ָ��
*�����      1 | 0
*˵����      ��ȡCAN���������ݣ����û�����ݣ�����0
		��CAN�е�����ȡ��������J1939_MESSAGE�ṹ����
		Ĭ��֧��4·CANӲ�����շ���������4·��ֻ��������Ӧ��Can_Node���ش�������
		������Select_CAN_NODE�����ֲ��䡣��ֱ�ӷ��أ�return 0��
*/

int J1939_CAN_Receive(J1939_MESSAGE *MsgPtr)
{

	switch (Can_Node)
	{
		case  Select_CAN_NODE_1:
		{
			if("��Ĵ���")//�ж�CANӲ��1�Ƿ������ݵ���
			{
				//��Ĵ��룬��CANӲ��1 �н����ݶ�ȡ�󣬴��� MsgPtr
				return 1;
			}
			return 0;
			break;
		}
		case  Select_CAN_NODE_2:
		{
			if("��Ĵ���")//�ж�CANӲ��2�Ƿ������ݵ���
			{
				//��Ĵ��룬��CANӲ��2 �н����ݶ�ȡ�󣬴��� MsgPtr
				return 1;
			}
			return 0;
			break;

		}
		case  Select_CAN_NODE_3:
		{
			if("��Ĵ���")//�ж�CANӲ��3�Ƿ������ݵ���
			{
				//��Ĵ��룬��CANӲ��3 �н����ݶ�ȡ�󣬴��� MsgPtr
				return 1;
			}
			return 0;
			break;

		}
		case  Select_CAN_NODE_4:
		{
			if("��Ĵ���")//�ж�CANӲ��4�Ƿ������ݵ���
			{
				//��Ĵ��룬��CANӲ��4 �н����ݶ�ȡ�󣬴��� MsgPtr
				return 1;
			}
			return 0;
			break;
		}
		default  :
		{
			return 0;//û����Ϣ
			break;
		}
	}
	return 0;//û����Ϣ
}

/*��ʹ���ж�ģʽ����������ĺ���������ֲ*/
#if J1939_POLL_ECAN == J1939_FALSE
/*
*���룺
*�����
*˵����ʹ�ܽ����ж�
*/
	void J1939_RXinterruptEnable()
	{
		;
	}
/*
*���룺
*�����
*˵����ʧ�ܽ����ж�
*/
	void J1939_RXinterruptDisable()
	{
		;
	}
/*
*���룺
*�����
*˵����ʹ�ܷ����ж�
*/
	void J1939_TXinterruptEnable()
	{
		;
	}
/*
*���룺
*�����
*˵����ʧ�ܷ����ж�
*/
	void J1939_TXinterruptDisable()
	{
		;
	}
/*
*���룺
*�����
*˵�������������жϱ���λ����Э��ջ���ж�ģʽ�£�Ҫ������Ϣ�������ô˺���
	CAN�����������ͽ�ֱ�Ӱ���Ϣ���ͳ�ȥ������ҪЭ���ڵ����κ�can��������
*/
	void J1939_TXinterruptOk()
	{
		;
	}
/*
*���룺
*�����
*˵�������CAN������ص��жϲ�����ʶλ�������������жϱ�־λ�������жϱ�
	־λ��can���ߴ����ʶλ��
*/
	void CAN_identifier_clc()
	{
		;
	}
#endif

#endif