#ifndef _LQ1000_H_
#define _LQ1000_H_
#include <windows.h>


/**
 * @brief ����TCP���񣬲���ָ���Ķ˿ڽ������ݼ���
 *
 * @param uPort ָ����������ʱ�����Ķ˿ں�
 * @return ����������������1,���򷵻�-1
 *
 * @see StopService
 */
int _stdcall StartServiceTCP(USHORT uPort);



/**
 * @brief ����UDP���񣬲���ָ���Ķ˿ڽ������ݼ���
 *
 * @param uPort ָ����������ʱ�����Ķ˿ں�
 * @return ����������������1,���򷵻�-1
 *
 * @see StopService
 */
int _stdcall StartServiceUDP(USHORT uPort);





/**
 * @brief ֹͣ����
 */
void  _stdcall StopService();



/**
 * @brief ��ȡ�ն˷��͵����ĵ��µ�����֡
 *        �ú����������ȴ���ֱ����ȡ����֡�ŷ��ء������ķ���ֹͣʱ��ֱ�ӷ���-1��
 *
 * @return ��ȡ����֡ʱ����֡���ͺţ�����ֹͣʱ����-1
 * ���� 1 ��ʾ��½֡
 * ���� 2 ��ʾ����֡
 * ���� 3 ��ʾ������֡
 * ���� 4 ��ʾDTU��������豸�ϴ�������֡
 *
 */
int  _stdcall WaitFrame();





/**
 * @brief ����ȡ����֡ʱ�����ô˺�����ȡ�ϴ���֡���ն˱��
 *
 * @return �����ն˱�ţ���Χ��1-9999��
 *
 */
int _stdcall GetDtuNum();



/**
 * @brief ����ȡ����¼֡ʱ�����ô˺�����ȡ�ϴ���֡���ն˵� SIM����
 *
 * @param simNum[] ������ֽ������ָ�룬���ڴ�� SIM�����ַ�����Ϊ11���ֽڳ��ȡ�
 *
 * @return       ����ʱ������ʵ�ʻ�õ� SIM�����ַ������ȡ�
 *               ���� 0ʱ ��ʾ�ն�δ ���� SIM����
 */
int  _stdcall GetSimNum( char simNum[] );






/**
 * @brief �������ն˴�������豸͸������
 *
 * @param rtuNum  �ն˱��
 * @param cmd[]   �����ָ���ֽ�����
 * @param len     �����ָ�����鳤��
 * @return        ���ط��͵�֡��(0-65535), ���� -1 ʱ��ʾ�ն�δ��½��������
 *
 * @sample    ��1���ն˵�����豸͸��һ�� Modbus-RTU Э������
 *
 *            unsigned char cmd[] = { 0x01, 0x03, 0x00, 0x01, 0x00, 0x02, 0x95, 0xCB };
 *            int len = 8;
 *            SendSerialData( 1, cmd, 8 );
 */
int  _stdcall SendSerialData( int rtuNum, unsigned char cmd[], int len );





/**
 * @brief ��WaitFrame��������4ʱ�����ñ�������ȡ�ն˴�������豸�ϴ�������
 *
 * @param data[] ������ֽ������ָ�룬���ڱ�������豸��Ӧ������
 * @return       ����ʵ�ʻ�õ����ݰ����ֽ���������豸û�������ϴ�ʱ���� -1
 */
int _stdcall GetSerialData(unsigned char data[]); 





#endif
