#ifndef _LQ1000_H_
#define _LQ1000_H_
#include <windows.h>


/**
 * @brief 启动TCP服务，并在指定的端口进行数据监听
 *
 * @param uPort 指定服务启动时监听的端口号
 * @return 服务启动正常返回1,否则返回-1
 *
 * @see StopService
 */
int _stdcall StartServiceTCP(USHORT uPort);



/**
 * @brief 启动UDP服务，并在指定的端口进行数据监听
 *
 * @param uPort 指定服务启动时监听的端口号
 * @return 服务启动正常返回1,否则返回-1
 *
 * @see StopService
 */
int _stdcall StartServiceUDP(USHORT uPort);





/**
 * @brief 停止服务
 */
void  _stdcall StopService();



/**
 * @brief 获取终端发送到中心的新的数据帧
 *        该函数会阻塞等待，直到获取了新帧才返回。当中心服务停止时，直接返回-1。
 *
 * @return 获取到新帧时返回帧类型号，服务停止时返回-1
 * 返回 1 表示登陆帧
 * 返回 2 表示下线帧
 * 返回 3 表示心跳包帧
 * 返回 4 表示DTU串口外接设备上传的数据帧
 *
 */
int  _stdcall WaitFrame();





/**
 * @brief 当获取到新帧时，调用此函数获取上传该帧的终端编号
 *
 * @return 返回终端编号（范围在1-9999）
 *
 */
int _stdcall GetDtuNum();



/**
 * @brief 当获取到登录帧时，调用此函数获取上传该帧的终端的 SIM卡号
 *
 * @param simNum[] 传入的字节数组的指针，用于存放 SIM卡号字符串，为11个字节长度。
 *
 * @return       正常时，返回实际获得的 SIM卡号字符串长度。
 *               返回 0时 表示终端未 设置 SIM卡号
 */
int  _stdcall GetSimNum( char simNum[] );






/**
 * @brief 中心向终端串口外接设备透传数据
 *
 * @param rtuNum  终端编号
 * @param cmd[]   传入的指令字节数组
 * @param len     传入的指令数组长度
 * @return        返回发送的帧号(0-65535), 返回 -1 时表示终端未登陆或已下线
 *
 * @sample    向1号终端的外接设备透传一条 Modbus-RTU 协议命令
 *
 *            unsigned char cmd[] = { 0x01, 0x03, 0x00, 0x01, 0x00, 0x02, 0x95, 0xCB };
 *            int len = 8;
 *            SendSerialData( 1, cmd, 8 );
 */
int  _stdcall SendSerialData( int rtuNum, unsigned char cmd[], int len );





/**
 * @brief 当WaitFrame函数返回4时，调用本函数获取终端串口外接设备上传的数据
 *
 * @param data[] 传入的字节数组的指针，用于保存外接设备的应答数据
 * @return       返回实际获得的数据包的字节数，外接设备没有数据上传时返回 -1
 */
int _stdcall GetSerialData(unsigned char data[]); 





#endif
