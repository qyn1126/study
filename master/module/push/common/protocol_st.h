#ifndef _PROTOCOL_DEF_H_
#define _PROTOCOL_DEF_H_

#include "stdio.h"
#include "protocol.h"
#include <net/proto/net_archive.h>
#include <net/proto/command_header.h>

using namespace klib::net;

// #pragma pack(1)

/////////////////////////////////////////////////////////////////////////
//��ʼ����Э��: C2S 
//// ��ѯ�߼��������ĵ�ַ
struct PT_CMD_QUERY_LOGIC_SERVER {
	PT_CMD_QUERY_LOGIC_SERVER ()  {
		//this->ver = ADVERTISE_VERSION;
		//this->cmd = CMD_QUERY_LOGIC_SERVER;
		//this->encrypt = E_None;
	}
	
	friend net_archive& operator << (net_archive& ar, PT_CMD_QUERY_LOGIC_SERVER& pt) {
		//ar << *(COMMAND_HEADER*) &pt;
	
		ar << pt.uuid; 
		return ar;
	}
	
	friend net_archive& operator >> (net_archive& ar, PT_CMD_QUERY_LOGIC_SERVER& pt) {
		//ar >> *(COMMAND_HEADER*) &pt;
		
		ar >> pt.uuid; 
		return ar;
	}
	
	
	UINT  uuid;  
};


//// ���صĿ��е��߼���������IP+PORT
struct PT_CMD_QUERY_LOGIC_SERVER_ACK {
	PT_CMD_QUERY_LOGIC_SERVER_ACK ()  {
		//this->ver = ADVERTISE_VERSION;
		//this->cmd = CMD_QUERY_LOGIC_SERVER_ACK;
		//this->encrypt = E_None;
	}
	
	friend net_archive& operator << (net_archive& ar, PT_CMD_QUERY_LOGIC_SERVER_ACK& pt) {
		//ar << *(COMMAND_HEADER*) &pt;
	
		ar << pt.uLogicIP; 
		ar << pt.uLogicUdpPort; 
		ar << pt.uLogicTcpPort; 
		return ar;
	}
	
	friend net_archive& operator >> (net_archive& ar, PT_CMD_QUERY_LOGIC_SERVER_ACK& pt) {
		//ar >> *(COMMAND_HEADER*) &pt;
		
		ar >> pt.uLogicIP; 
		ar >> pt.uLogicUdpPort; 
		ar >> pt.uLogicTcpPort; 
		return ar;
	}
	
	
	UINT  uLogicIP;  
	USHORT  uLogicUdpPort;  
	USHORT  uLogicTcpPort;  
};


//// ��ѯ��ǰ���°汾
struct PT_CMD_QUERY_CURRENT_VERSION {
	PT_CMD_QUERY_CURRENT_VERSION ()  {
		//this->ver = ADVERTISE_VERSION;
		//this->cmd = CMD_QUERY_CURRENT_VERSION;
		//this->encrypt = E_None;
	}
	
	friend net_archive& operator << (net_archive& ar, PT_CMD_QUERY_CURRENT_VERSION& pt) {
		//ar << *(COMMAND_HEADER*) &pt;
	
		ar << pt.uCurVerValue; 
		ar << pt.strVersion; 
		return ar;
	}
	
	friend net_archive& operator >> (net_archive& ar, PT_CMD_QUERY_CURRENT_VERSION& pt) {
		//ar >> *(COMMAND_HEADER*) &pt;
		
		ar >> pt.uCurVerValue; 
		ar >> pt.strVersion; 
		return ar;
	}
	
	
	UINT  uCurVerValue;   	//  ��ǰ�汾ֵ
	std::string  strVersion;   	//  �汾���ַ���
};


//// ���ص�ǰ�İ汾��
struct PT_CMD_QUERY_CURRENT_VERSION_ACK {
	PT_CMD_QUERY_CURRENT_VERSION_ACK ()  {
		//this->ver = ADVERTISE_VERSION;
		//this->cmd = CMD_QUERY_CURRENT_VERSION_ACK;
		//this->encrypt = E_None;
	}
	
	friend net_archive& operator << (net_archive& ar, PT_CMD_QUERY_CURRENT_VERSION_ACK& pt) {
		//ar << *(COMMAND_HEADER*) &pt;
	
		ar << pt.strVersion; 
		ar << pt.uVersionValue; 
		ar << pt.strUpdateUrl; 
		ar << pt.strUpdateSign; 
		ar << pt.bForceUpdate; 
		ar << pt.bClientRequest; 
		return ar;
	}
	
	friend net_archive& operator >> (net_archive& ar, PT_CMD_QUERY_CURRENT_VERSION_ACK& pt) {
		//ar >> *(COMMAND_HEADER*) &pt;
		
		ar >> pt.strVersion; 
		ar >> pt.uVersionValue; 
		ar >> pt.strUpdateUrl; 
		ar >> pt.strUpdateSign; 
		ar >> pt.bForceUpdate; 
		ar >> pt.bClientRequest; 
		return ar;
	}
	
	
	std::string  strVersion;   	//  �汾���ַ���ֵ
	UINT  uVersionValue;   	//  �汾������ֵ
	std::string  strUpdateUrl;   	//  ���°��ĵ�ַ
	std::string  strUpdateSign;   	//  ����ǩ��
	BOOL  bForceUpdate;   	//  ǿ�Ƹ���
	BOOL  bClientRequest;   	//  �Ƿ��ǿͻ������������
};


//// ���¶�֪ͨ������������Ϣ
struct PT_CMD_ONLINE {
	PT_CMD_ONLINE ()  {
		//this->ver = ADVERTISE_VERSION;
		//this->cmd = CMD_ONLINE;
		//this->encrypt = E_None;
	}
	
	friend net_archive& operator << (net_archive& ar, PT_CMD_ONLINE& pt) {
		//ar << *(COMMAND_HEADER*) &pt;
	
		ar << pt.strMac; 
		ar << pt.strChannel; 
		ar << pt.uLastMsgID; 
		ar << pt.strLoginName; 
		ar << pt.uVersion; 
		ar << pt.strAccount; 
		return ar;
	}
	
	friend net_archive& operator >> (net_archive& ar, PT_CMD_ONLINE& pt) {
		//ar >> *(COMMAND_HEADER*) &pt;
		
		ar >> pt.strMac; 
		ar >> pt.strChannel; 
		ar >> pt.uLastMsgID; 
		ar >> pt.strLoginName; 
		ar >> pt.uVersion; 
		ar >> pt.strAccount; 
		return ar;
	}
	
	
	std::string  strMac;   	//  mac��ַ
	std::string  strChannel;   	//  ����
	UINT64  uLastMsgID;   	//  ����յ�����ϢID
	std::string  strLoginName;   	//  ���Եĵ�½��
	UINT  uVersion;   	//  �汾ֵ������ֵ�Ƚϸ���Щ
	std::string  strAccount;   	//  �û����ʺ�(ע����û�)
};


//// ������Ϣ�Ļظ���Ϣ
struct PT_CMD_ONLINE_ACK {
	PT_CMD_ONLINE_ACK ()  {
		//this->ver = ADVERTISE_VERSION;
		//this->cmd = CMD_ONLINE_ACK;
		//this->encrypt = E_None;
	}
	
	friend net_archive& operator << (net_archive& ar, PT_CMD_ONLINE_ACK& pt) {
		//ar << *(COMMAND_HEADER*) &pt;
	
		ar << pt.bStartMini; 
		ar << pt.uuid; 
		ar << pt.msgId; 
		return ar;
	}
	
	friend net_archive& operator >> (net_archive& ar, PT_CMD_ONLINE_ACK& pt) {
		//ar >> *(COMMAND_HEADER*) &pt;
		
		ar >> pt.bStartMini; 
		ar >> pt.uuid; 
		ar >> pt.msgId; 
		return ar;
	}
	
	
	BOOL  bStartMini;   	//  ��������ҳ
	UINT64  uuid;   	//  ���ɵ�Ψһ��ʶ��ID��
	UINT64  msgId;   	//  ��Ҫչʾ����ϢID
};


//// ������Ϣ���ͻ����˳���ʱ����
struct PT_CMD_OFFLINE {
	PT_CMD_OFFLINE ()  {
		//this->ver = ADVERTISE_VERSION;
		//this->cmd = CMD_OFFLINE;
		//this->encrypt = E_None;
	}
	
	friend net_archive& operator << (net_archive& ar, PT_CMD_OFFLINE& pt) {
		//ar << *(COMMAND_HEADER*) &pt;
	
		ar << pt.uuid; 
		return ar;
	}
	
	friend net_archive& operator >> (net_archive& ar, PT_CMD_OFFLINE& pt) {
		//ar >> *(COMMAND_HEADER*) &pt;
		
		ar >> pt.uuid; 
		return ar;
	}
	
	
	UINT64  uuid;   	//  ���ɵ�Ψһ��ʶ��ID��
};


//// ������Ϣ�Ļظ���Ϣ������������ѡ�񲻻ظ���Ϣ
struct PT_CMD_OFFLINE_ACK {
	PT_CMD_OFFLINE_ACK ()  {
		//this->ver = ADVERTISE_VERSION;
		//this->cmd = CMD_OFFLINE_ACK;
		//this->encrypt = E_None;
	}
	
	friend net_archive& operator << (net_archive& ar, PT_CMD_OFFLINE_ACK& pt) {
		//ar << *(COMMAND_HEADER*) &pt;
	
		
		return ar;
	}
	
	friend net_archive& operator >> (net_archive& ar, PT_CMD_OFFLINE_ACK& pt) {
		//ar >> *(COMMAND_HEADER*) &pt;
		
		
		return ar;
	}
	
	
	
};


//// ��Ϣ֪ͨЭ��
struct PT_CMD_MESSAGE_NOTIFY {
	PT_CMD_MESSAGE_NOTIFY ()  {
		//this->ver = ADVERTISE_VERSION;
		//this->cmd = CMD_MESSAGE_NOTIFY;
		//this->encrypt = E_None;
	}
	
	friend net_archive& operator << (net_archive& ar, PT_CMD_MESSAGE_NOTIFY& pt) {
		//ar << *(COMMAND_HEADER*) &pt;
	
		ar << pt.msgID; 
		return ar;
	}
	
	friend net_archive& operator >> (net_archive& ar, PT_CMD_MESSAGE_NOTIFY& pt) {
		//ar >> *(COMMAND_HEADER*) &pt;
		
		ar >> pt.msgID; 
		return ar;
	}
	
	
	UINT64  msgID;   	//  ��ϢID
};


//// ��Ϣ����Э��
struct PT_CMD_MESSAGE_CONTENT {
	PT_CMD_MESSAGE_CONTENT ()  {
		//this->ver = ADVERTISE_VERSION;
		//this->cmd = CMD_MESSAGE_CONTENT;
		//this->encrypt = E_None;
	}
	
	friend net_archive& operator << (net_archive& ar, PT_CMD_MESSAGE_CONTENT& pt) {
		//ar << *(COMMAND_HEADER*) &pt;
	
		ar << pt.uMsgID; 
		ar << pt.uMsgType; 
		ar << pt.uDelayFetch; 
		ar << pt.uDelayShow; 
		ar << pt.uShowTime; 
		ar << pt.strSign; 
		ar << pt.strMsgContent; 
		return ar;
	}
	
	friend net_archive& operator >> (net_archive& ar, PT_CMD_MESSAGE_CONTENT& pt) {
		//ar >> *(COMMAND_HEADER*) &pt;
		
		ar >> pt.uMsgID; 
		ar >> pt.uMsgType; 
		ar >> pt.uDelayFetch; 
		ar >> pt.uDelayShow; 
		ar >> pt.uShowTime; 
		ar >> pt.strSign; 
		ar >> pt.strMsgContent; 
		return ar;
	}
	
	
	UINT64  uMsgID;   	//  ��ϢID
	UINT32  uMsgType;   	//  ��Ϣ����
	UINT32  uDelayFetch;   	//  �ӳٶ೤ʱ���ȡ��Ϣ
	UINT32  uDelayShow;   	//  ��ʾ�ӳ�ʱ�䣨��ָ��Ҫ�ӳٶ���ʱ����ʾ��
	UINT32  uShowTime;   	//  ��ʾ��ʱ�������Ϊ0��һֱ��ʾ��
	std::string  strSign;   	//  ��Ϣ���ݵ�ǩ������������ݵ�md5ֵ,ʹ��ǩ���㷨ǩ����
	std::string  strMsgContent;   	//  ��Ϣ����
};


//// ��Ϣȷ��
struct PT_CMD_MESSAGE_CONTENT_ACK {
	PT_CMD_MESSAGE_CONTENT_ACK ()  {
		//this->ver = ADVERTISE_VERSION;
		//this->cmd = CMD_MESSAGE_CONTENT_ACK;
		//this->encrypt = E_None;
	}
	
	friend net_archive& operator << (net_archive& ar, PT_CMD_MESSAGE_CONTENT_ACK& pt) {
		//ar << *(COMMAND_HEADER*) &pt;
	
		ar << pt.uMsgID; 
		ar << pt.emOpResult; 
		return ar;
	}
	
	friend net_archive& operator >> (net_archive& ar, PT_CMD_MESSAGE_CONTENT_ACK& pt) {
		//ar >> *(COMMAND_HEADER*) &pt;
		
		ar >> pt.uMsgID; 
		ar >> pt.emOpResult; 
		return ar;
	}
	
	
	UINT64  uMsgID;   	//  Ҫȷ�ϵ���ϢID
	UINT  emOpResult;   	//  ��ʾ���
};


// #pragma pack()

#endif