#if (UNIT_TEST_TYPE == TEST_TYPE_GTEST)
#include <gtest/gtest.h>
#endif

#include "utest_main.h"

/* Input Auto Parameters >>> */
//void *input_p_arg;
/* Input Auto Parameters <<<*/

/* Input Global Parameters >>> */
Type_uByte wubAbnormalGlobalFlag1;
/* Input Global Parameters <<<*/


/* Input Stub Function Return Value >>> */
int32   input_halRet;
uint32  input_ipc_ready;
int32   input_cnt;
int32   input_ipc_ret;
/* Input Stub Function Return Value <<< */


//static uint8 uart_routing_value = UART_CH_17;
//uint8 uart_get_routing(void)
//{
//    return uart_routing_value;
//}

static uint8 uart_buff0[2][UART_BUFF_SIZE];
static uint8 uart_buff1[2][UART_BUFF_SIZE];
static uint8 uart_buff2[2][UART_BUFF_SIZE];
static uint8 uart_buff3[2][UART_BUFF_SIZE];

static uint8 *uart_buff[UART_CH_MAX][2] =
{
    { uart_buff0[0], uart_buff0[1] },
    { uart_buff1[0], uart_buff1[1] },
    { uart_buff2[0], uart_buff2[1] },
    { uart_buff3[0], uart_buff3[1] },
};

static uint8 etc_data[IPC_BUFF_SIZE] = {0};
static uint8 panel_data[IPC_BUFF_SIZE] = {0};
static uint8 fcam_data[IPC_BUFF_SIZE] = {0};
static uint8 rcam_data[IPC_BUFF_SIZE] = {0};

tcc_ipc_ch_info ipc_ch_info[IPC_SVC_CH_MAX] = {};

void uart_intr_rx_probe(uint32 ch, const struct intr_data *intr)
{
}

void uart_flush_rx(uint32 ch)
{
}

void uart_intr_tx_probe(uint32 ch, const struct intr_data *intr)
{
}

void uart_flush_tx(uint32 ch)
{
}

void tcc_ipc_register_cb_func(IPC_SVC_CH ch, uint8 id, tcc_ipc_call_back func, void *arg1, void *arg2)
{
}

void OSAL_TaskDelay(uint32 millisecond)
{
}

extern void RCAMRoutingAppIPCHandle(uint16 cmd2, uint8 *data, uint16 length);

/* Stub Function 1 */
int32 HAL_Ioctl(HAL_HANDLE HALHandle, uint32 ulCommand, void* param1, void* param2, void* param3, void* param4)
{
    uint32 *ipc_ready_p = (uint32 *)param1;
    *ipc_ready_p = input_ipc_ready;
    return input_halRet;
}

/* Stub Function 2 */
int32 uart_intr_rx(uint32 ch, uint8 *buf, uint32 size)
{
    return input_cnt;
}

/* Stub Function 3 */
int32 tcc_ipc_send_packet(IPC_SVC_CH ch, uint16 cmd1, uint16 cmd2, const uint8* data, uint16 length)
{
    return input_ipc_ret;
}

static Type_uByte RCAMRoutingAppTask(void)
{
    Type_uByte aubRes = RES_NG;

    int32  ipc_ret = 0;
    int32  halRet = 0;
    uint32 ipc_ready = 0;
    int32  cnt;
    int32  i;
    struct intr_data rx_data;
    struct intr_data tx_data;

    rx_data.xmit_buf = uart_buff[UART_CH_8][UART_MODE_RX];
    rx_data.size = UART_BUFF_SIZE;
    tx_data.xmit_buf = uart_buff[UART_CH_8][UART_MODE_TX];
    tx_data.size = UART_BUFF_SIZE;

    uart_intr_rx_probe(UART_CH_8, &rx_data);
    uart_flush_rx(UART_CH_8);

    uart_intr_tx_probe(UART_CH_8, &tx_data);
    uart_flush_tx(UART_CH_8);

    /* register ipc handler */
    tcc_ipc_register_cb_func(IPC_SVC_CH_MAIN, TCC_IPC_CMD_RCAM, (tcc_ipc_call_back)RCAMRoutingAppIPCHandle, NULL, NULL);

    //while (1u) {

    /* After IPC connection is successful, read the data stored in uartdrv */
    halRet = HAL_Ioctl(ipc_ch_info[IPC_SVC_CH_MAIN].halHandle, IOCTL_IPC_ISREADY, (void *)&ipc_ready, 0, 0, 0);
    if((HAL_OK == halRet) && (ipc_ready == 1))
    {
        cnt = uart_intr_rx(UART_CH_8, rcam_data, IPC_BUFF_SIZE);
        if(cnt != 0)
        {
            ipc_ret = tcc_ipc_send_packet(IPC_SVC_CH_MAIN, (uint16)TCC_IPC_CMD_RCAM, (uint16)TCC_IPC_CMD_RCAM_FROM_R5, (uint8*)rcam_data, (uint16)cnt);
            if(HAL_OK == ipc_ret)
            {
                ROUTING_DEBUG("\r\nR-R5-A53:");
                for(i = 0; i < cnt; i++)
                {
                    ROUTING_DEBUG("[0x%02X]", rcam_data[i]);
                    if (wubAbnormalGlobalFlag1 != 0 && i > 100){
                        break;
                    }
                }
                if(i == cnt)
                {
                    ROUTING_DEBUG(" (cnt=%d) \r\n",cnt);
                    aubRes = RES_OK;
                }
            }
            else
            {
                printf("[%s] ipc send err=%d.\r\n", __func__, ipc_ret);
            }
        }
    }

    OSAL_TaskDelay(5);
    //}

    return aubRes;
}

/********************************************************************************************/
Type_uByte wubResValue;
/********************************************************************************************/
/*                           Structure Type Definition Section                              */
/********************************************************************************************/

/* Test Case Num */
#define    GTESTCASE_MAX_NUM        (9U)

/* In put */
#define    IN_PARA_VALUE1
#define    IN_GLOB_VALUE1       (wubAbnormalGlobalFlag1)
#define    IN_STUB_VALUE1       (input_halRet)
#define    IN_STUB_VALUE2       (input_ipc_ready)
#define    IN_STUB_VALUE3       (input_cnt)
#define    IN_STUB_VALUE4       (input_ipc_ret)

/* Actual output Must constant */
#define    OUT_ACT_RES1        (wubResValue)

/* Expected output Must variable */
#define    CASE1_OUT_EXP_RES1        (RES_NG)

#define    CASE2_OUT_EXP_RES1        (RES_NG)

#define    CASE3_OUT_EXP_RES1        (RES_NG)

#define    CASE4_OUT_EXP_RES1        (RES_NG)

#define    CASE5_OUT_EXP_RES1        (RES_OK)

#define    CASE6_OUT_EXP_RES1        (RES_OK)

#define    CASE7_OUT_EXP_RES1        (RES_OK)

#define    CASE8_OUT_EXP_RES1        (RES_NG)

#define    CASE9_OUT_EXP_RES1        (RES_NG)

/* Test Case Value Set */
void TestCaseInit(Type_uByte CaseNum)
{
    switch (CaseNum){
    case 1:
        /* halRet Error (RES_NG) (Abnormal1) */
        input_halRet = HAL_ERR_NO_ACK;
        input_ipc_ready = 1;
        input_cnt = 300;
        input_ipc_ret = HAL_OK;
        wubAbnormalGlobalFlag1 = 0;
        break;
    case 2:
        /* ipc_ready Error (RES_NG) (Abnormal2) */
        input_halRet = HAL_OK;
        input_ipc_ready = 3;
        input_cnt = 300;
        input_ipc_ret = HAL_OK;
        wubAbnormalGlobalFlag1 = 0;
        break;
    case 3:
        /* halRet&ipc_ready Error (RES_NG) (Abnormal3) */
        input_halRet = HAL_ERR_NOT_INITIALIZED;
        input_ipc_ready = 0;
        input_cnt = 300;
        input_ipc_ret = HAL_OK;
        wubAbnormalGlobalFlag1 = 0;
        break;
    case 4:
        /* cnt Error (RES_NG) (Abnormal4) */
        input_halRet = HAL_OK;
        input_ipc_ready = 1;
        input_cnt = 0;
        input_ipc_ret = HAL_OK;
        wubAbnormalGlobalFlag1 = 0;
        break;
    case 5:
        /* Count Normal 300 (RES_OK) (Normal1) */
        input_halRet = HAL_OK;
        input_ipc_ready = 1;
        input_cnt = 512;
        input_ipc_ret = HAL_OK;
        wubAbnormalGlobalFlag1 = 0;
        break;
    case 6:
        /* Count Boundary 512 (RES_OK) (Boundary1) */
        input_halRet = HAL_OK;
        input_ipc_ready = 1;
        input_cnt = 512;
        input_ipc_ret = HAL_OK;
        wubAbnormalGlobalFlag1 = 0;
        break;
    case 7:
        /* Count greater than 512 (RES_OK) (Abnormal5) */
        input_halRet = HAL_OK;
        input_ipc_ready = 1;
        input_cnt = 1200;
        input_ipc_ret = HAL_OK;
        wubAbnormalGlobalFlag1 = 0;
        break;
    case 8:
        /* ipc_ret error (RES_NG) (Abnormal6) */
        input_halRet = HAL_OK;
        input_ipc_ready = 1;
        input_cnt = 250;
        input_ipc_ret = HAL_ERR_TIME_OUT;
        wubAbnormalGlobalFlag1 = 0;
        break;
    case 9:
        /* Transfor length error (RES_NG) (Abnormal7) */
        input_halRet = HAL_OK;
        input_ipc_ready = 1;
        input_cnt = 480;
        input_ipc_ret = HAL_OK;
        wubAbnormalGlobalFlag1 = 1;
        break;
    default:
        printf("\r\n init Error \r\n");
        break;
    }
}
/********************************************************************************************/
typedef struct{
    Type_uByte (*func)(void);
}Gtest_Tbl_ts;

/********************************************************************************************/
/*                                                                                          */
/********************************************************************************************/

#if (GTESTCASE_MAX_NUM >= 1)
Type_uByte xxxGtestNo1(void)
{
    Type_uByte ubRes;

    /* Edit start */
    ubRes = RCAMRoutingAppTask();
    /* Edit End */

    return ubRes;
}
#endif

#if (GTESTCASE_MAX_NUM >= 2)
Type_uByte xxxGtestNo2(void)
{
    Type_uByte ubRes;

    /* Edit start */
    ubRes = RCAMRoutingAppTask();
    /* Edit End */

    return ubRes;
}
#endif

#if (GTESTCASE_MAX_NUM >= 3)
Type_uByte xxxGtestNo3(void)
{
    Type_uByte ubRes;

    /* Edit start */
    ubRes = RCAMRoutingAppTask();
    /* Edit End */

    return ubRes;
}
#endif

#if (GTESTCASE_MAX_NUM >= 4)
Type_uByte xxxGtestNo4(void)
{
    Type_uByte ubRes;

    /* Edit start */
    ubRes = RCAMRoutingAppTask();
    /* Edit End */

    return ubRes;
}
#endif

#if (GTESTCASE_MAX_NUM >= 5)
Type_uByte xxxGtestNo5(void)
{
    Type_uByte ubRes;

    /* Edit start */
    ubRes = RCAMRoutingAppTask();
    /* Edit End */

    return ubRes;
}
#endif

#if (GTESTCASE_MAX_NUM >= 6)
Type_uByte xxxGtestNo6(void)
{
    Type_uByte ubRes;

    /* Edit start */
    ubRes = RCAMRoutingAppTask();
    /* Edit End */

    return ubRes;
}
#endif

#if (GTESTCASE_MAX_NUM >= 7)
Type_uByte xxxGtestNo7(void)
{
    Type_uByte ubRes;

    /* Edit start */
    ubRes = RCAMRoutingAppTask();
    /* Edit End */

    return ubRes;
}
#endif

#if (GTESTCASE_MAX_NUM >= 8)
Type_uByte xxxGtestNo8(void)
{
    Type_uByte ubRes;

    /* Edit start */
    ubRes = RCAMRoutingAppTask();
    /* Edit End */

    return ubRes;
}
#endif

#if (GTESTCASE_MAX_NUM >= 9)
Type_uByte xxxGtestNo9(void)
{
    Type_uByte ubRes;

    /* Edit start */
    ubRes = RCAMRoutingAppTask();
    /* Edit End */

    return ubRes;
}
#endif

/********************************************************************************************/
/*                           Auto Coding                                                    */
/********************************************************************************************/
#if (UNIT_TEST_TYPE == TEST_TYPE_GTEST)

class RCAMRoutingAppTask : public testing::Test {
protected:  // You should make the members protected s.t. they can be
    // accessed from sub-classes.
    static void SetUpTestCase() {
        RecordProperty("input_para_input_halRet", "range{-15~0}_boundary{-15,0}_median{-10,-5}_error{-15~-1}");
        RecordProperty("input_para_input_ipc_ready", "range{0~0xffffffff}_boundary{0,0xffffffff}_median{1,10}_error{0}");
        RecordProperty("input_para_input_cnt", "range{0~512}_boundary{0,512}_median{200,300}_error{0}");
        RecordProperty("input_para_ipc_ret", "range{-15~0}_boundary{-15,0}_median{-10,-5}_error{-15~-1}");
        RecordProperty("Author", "Liming");
    }
};

#if (GTESTCASE_MAX_NUM >= 1)
TEST_F(RCAMRoutingAppTask,Abnormal1)
{
    /* Value init */
    TestCaseInit(1);

    /* Input Value */
    RecordProperty("input_stub_input_halRet", IN_STUB_VALUE1);
    RecordProperty("input_stub_input_ipc_ready", IN_STUB_VALUE2);
    RecordProperty("input_stub_input_cnt", IN_STUB_VALUE3);
    RecordProperty("input_stub_input_ipc_ret", IN_STUB_VALUE4);
    RecordProperty("input_glob_wubAbnormalGlobalFlag1", IN_GLOB_VALUE1);

    /* Run Function */
    OUT_ACT_RES1 = xxxGtestNo1();

    EXPECT_EQ(CASE1_OUT_EXP_RES1, OUT_ACT_RES1);

    /* Output Value */
    RecordProperty("output_expected_result_aubRet", CASE1_OUT_EXP_RES1);
    RecordProperty("output_actual_result_aubRet", OUT_ACT_RES1);
}
#endif


#if (GTESTCASE_MAX_NUM >= 2)
TEST_F(RCAMRoutingAppTask,Abnormal2)
{
    /* Value init */
    TestCaseInit(2);

    /* Input Value */
    RecordProperty("input_stub_input_halRet", IN_STUB_VALUE1);
    RecordProperty("input_stub_input_ipc_ready", IN_STUB_VALUE2);
    RecordProperty("input_stub_input_cnt", IN_STUB_VALUE3);
    RecordProperty("input_stub_input_ipc_ret", IN_STUB_VALUE4);
    RecordProperty("input_glob_wubAbnormalGlobalFlag1", IN_GLOB_VALUE1);

    /* Run Function */
    OUT_ACT_RES1 = xxxGtestNo2();

    EXPECT_EQ(CASE2_OUT_EXP_RES1, OUT_ACT_RES1);

    /* Output Value */
    RecordProperty("output_expected_result_aubRet", CASE2_OUT_EXP_RES1);
    RecordProperty("output_actual_result_aubRet", OUT_ACT_RES1);
}
#endif


#if (GTESTCASE_MAX_NUM >= 3)
TEST_F(RCAMRoutingAppTask,Abnormal3)
{
    /* Value init */
    TestCaseInit(3);

    /* Input Value */
    RecordProperty("input_stub_input_halRet", IN_STUB_VALUE1);
    RecordProperty("input_stub_input_ipc_ready", IN_STUB_VALUE2);
    RecordProperty("input_stub_input_cnt", IN_STUB_VALUE3);
    RecordProperty("input_stub_input_ipc_ret", IN_STUB_VALUE4);
    RecordProperty("input_glob_wubAbnormalGlobalFlag1", IN_GLOB_VALUE1);

    /* Run Function */
    OUT_ACT_RES1 = xxxGtestNo3();

    EXPECT_EQ(CASE3_OUT_EXP_RES1, OUT_ACT_RES1);

    /* Output Value */
    RecordProperty("output_expected_result_aubRet", CASE3_OUT_EXP_RES1);
    RecordProperty("output_actual_result_aubRet", OUT_ACT_RES1);
}
#endif


#if (GTESTCASE_MAX_NUM >= 4)
TEST_F(RCAMRoutingAppTask,Abnormal4)
{
    /* Value init */
    TestCaseInit(4);

    /* Input Value */
    RecordProperty("input_stub_input_halRet", IN_STUB_VALUE1);
    RecordProperty("input_stub_input_ipc_ready", IN_STUB_VALUE2);
    RecordProperty("input_stub_input_cnt", IN_STUB_VALUE3);
    RecordProperty("input_stub_input_ipc_ret", IN_STUB_VALUE4);
    RecordProperty("input_glob_wubAbnormalGlobalFlag1", IN_GLOB_VALUE1);

    /* Run Function */
    OUT_ACT_RES1 = xxxGtestNo4();

    EXPECT_EQ(CASE4_OUT_EXP_RES1, OUT_ACT_RES1);

    /* Output Value */
    RecordProperty("output_expected_result_aubRet", CASE4_OUT_EXP_RES1);
    RecordProperty("output_actual_result_aubRet", OUT_ACT_RES1);
}
#endif

#if (GTESTCASE_MAX_NUM >= 5)
TEST_F(RCAMRoutingAppTask,Normal1)
{
    /* Value init */
    TestCaseInit(5);

    /* Input Value */
    RecordProperty("input_stub_input_halRet", IN_STUB_VALUE1);
    RecordProperty("input_stub_input_ipc_ready", IN_STUB_VALUE2);
    RecordProperty("input_stub_input_cnt", IN_STUB_VALUE3);
    RecordProperty("input_stub_input_ipc_ret", IN_STUB_VALUE4);
    RecordProperty("input_glob_wubAbnormalGlobalFlag1", IN_GLOB_VALUE1);

    /* Run Function */
    OUT_ACT_RES1 = xxxGtestNo5();

    EXPECT_EQ(CASE5_OUT_EXP_RES1, OUT_ACT_RES1);

    /* Output Value */
    RecordProperty("output_expected_result_aubRet", CASE5_OUT_EXP_RES1);
    RecordProperty("output_actual_result_aubRet", OUT_ACT_RES1);
}
#endif

#if (GTESTCASE_MAX_NUM >= 6)
TEST_F(RCAMRoutingAppTask,Boundary1)
{
    /* Value init */
    TestCaseInit(6);

    /* Input Value */
    RecordProperty("input_stub_input_halRet", IN_STUB_VALUE1);
    RecordProperty("input_stub_input_ipc_ready", IN_STUB_VALUE2);
    RecordProperty("input_stub_input_cnt", IN_STUB_VALUE3);
    RecordProperty("input_stub_input_ipc_ret", IN_STUB_VALUE4);
    RecordProperty("input_glob_wubAbnormalGlobalFlag1", IN_GLOB_VALUE1);

    /* Run Function */
    OUT_ACT_RES1 = xxxGtestNo6();

    EXPECT_EQ(CASE6_OUT_EXP_RES1, OUT_ACT_RES1);

    /* Output Value */
    RecordProperty("output_expected_result_aubRet", CASE6_OUT_EXP_RES1);
    RecordProperty("output_actual_result_aubRet", OUT_ACT_RES1);
}
#endif

#if (GTESTCASE_MAX_NUM >= 7)
TEST_F(RCAMRoutingAppTask,Abnormal5)
{
    /* Value init */
    TestCaseInit(7);

    /* Input Value */
    RecordProperty("input_stub_input_halRet", IN_STUB_VALUE1);
    RecordProperty("input_stub_input_ipc_ready", IN_STUB_VALUE2);
    RecordProperty("input_stub_input_cnt", IN_STUB_VALUE3);
    RecordProperty("input_stub_input_ipc_ret", IN_STUB_VALUE4);
    RecordProperty("input_glob_wubAbnormalGlobalFlag1", IN_GLOB_VALUE1);

    /* Run Function */
    OUT_ACT_RES1 = xxxGtestNo7();

    EXPECT_EQ(CASE7_OUT_EXP_RES1, OUT_ACT_RES1);

    /* Output Value */
    RecordProperty("output_expected_result_aubRet", CASE7_OUT_EXP_RES1);
    RecordProperty("output_actual_result_aubRet", OUT_ACT_RES1);
}
#endif

#if (GTESTCASE_MAX_NUM >= 8)
TEST_F(RCAMRoutingAppTask,Abnormal6)
{
    /* Value init */
    TestCaseInit(8);

    /* Input Value */
    RecordProperty("input_stub_input_halRet", IN_STUB_VALUE1);
    RecordProperty("input_stub_input_ipc_ready", IN_STUB_VALUE2);
    RecordProperty("input_stub_input_cnt", IN_STUB_VALUE3);
    RecordProperty("input_stub_input_ipc_ret", IN_STUB_VALUE4);
    RecordProperty("input_glob_wubAbnormalGlobalFlag1", IN_GLOB_VALUE1);

    /* Run Function */
    OUT_ACT_RES1 = xxxGtestNo8();

    EXPECT_EQ(CASE8_OUT_EXP_RES1, OUT_ACT_RES1);

    /* Output Value */
    RecordProperty("output_expected_result_aubRet", CASE8_OUT_EXP_RES1);
    RecordProperty("output_actual_result_aubRet", OUT_ACT_RES1);
}
#endif

#if (GTESTCASE_MAX_NUM >= 9)
TEST_F(RCAMRoutingAppTask,Abnormal7)
{
    /* Value init */
    TestCaseInit(9);

    /* Input Value */
    RecordProperty("input_stub_input_halRet", IN_STUB_VALUE1);
    RecordProperty("input_stub_input_ipc_ready", IN_STUB_VALUE2);
    RecordProperty("input_stub_input_cnt", IN_STUB_VALUE3);
    RecordProperty("input_stub_input_ipc_ret", IN_STUB_VALUE4);
    RecordProperty("input_glob_wubAbnormalGlobalFlag1", IN_GLOB_VALUE1);

    /* Run Function */
    OUT_ACT_RES1 = xxxGtestNo9();

    EXPECT_EQ(CASE9_OUT_EXP_RES1, OUT_ACT_RES1);

    /* Output Value */
    RecordProperty("output_expected_result_aubRet", CASE9_OUT_EXP_RES1);
    RecordProperty("output_actual_result_aubRet", OUT_ACT_RES1);
}
#endif

#endif
/********************************************************************************************/
/*                                  No editing                                              */
/********************************************************************************************/

Gtest_Tbl_ts xxxGtestTbl_tbl[] =
{
    #if (GTESTCASE_MAX_NUM >= 1)
    {xxxGtestNo1},
    #endif
    #if (GTESTCASE_MAX_NUM >= 2)
    {xxxGtestNo2},
    #endif
    #if (GTESTCASE_MAX_NUM >= 3)
    {xxxGtestNo3},
    #endif
    #if (GTESTCASE_MAX_NUM >= 4)
    {xxxGtestNo4},
    #endif
    #if (GTESTCASE_MAX_NUM >= 5)
    {xxxGtestNo5},
    #endif
    #if (GTESTCASE_MAX_NUM >= 6)
    {xxxGtestNo6},
    #endif
    #if (GTESTCASE_MAX_NUM >= 7)
    {xxxGtestNo7},
    #endif
    #if (GTESTCASE_MAX_NUM >= 8)
    {xxxGtestNo8},
    #endif
    #if (GTESTCASE_MAX_NUM >= 9)
    {xxxGtestNo9},
    #endif
};

#if (UNIT_TEST_TYPE == TEST_TYPE_GTEST)
/********************************************************************************************/
/*                      CPP     Main Loop                                                   */
/********************************************************************************************/

int main(int argc, char **argv)
{
    testing::GTEST_FLAG(output) = "xml:";
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

#else
/********************************************************************************************/
/*                          C   Main Loop                                                   */
/********************************************************************************************/
int main(void)
{
    Type_uByte Loop;

    for(Loop=0x00U;Loop < GTESTCASE_MAX_NUM;Loop++)
    {
        TestCaseInit(Loop + 1);
        xxxGtestTbl_tbl[Loop].func();
    }

    TestCaseInit(GTESTCASE_MAX_NUM + 1);

    return 0;
}

#endif
