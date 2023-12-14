#pragma once
#include "common.hpp"
#include <stdio.h>
#include <cstring>
#include <functional>
#include "rcc.hpp"

enum USARTWordLen
{
    UART_WORDLENGTH_7B    =      USART_CR1_M1,          /*!< 7-bit long UART frame */
    UART_WORDLENGTH_8B    =      0x00000000U,           /*!< 8-bit long UART frame */
    UART_WORDLENGTH_9B    =      USART_CR1_M0           /*!< 9-bit long UART frame */
};
enum USARTStopBit
{
    UART_STOPBITS_0_5     =         USART_CR2_STOP_0,                      /*!< UART frame with 0.5 stop bit  */
    UART_STOPBITS_1       =         0x00000000U,                           /*!< UART frame with 1 stop bit    */
    UART_STOPBITS_1_5     =         (USART_CR2_STOP_0 | USART_CR2_STOP_1), /*!< UART frame with 1.5 stop bits */
    UART_STOPBITS_2       =         USART_CR2_STOP_1  
};
enum USARTOverS
{
    UART_OVERSAMPLING_16     =     0x00000000U,         /*!< Oversampling by 16 */
    UART_OVERSAMPLING_8      =     USART_CR1_OVER8     /*!< Oversampling by 8  */
};
enum USARTMode
{
    UART_MODE_RX        =         USART_CR1_RE,                    /*!< RX mode        */
    UART_MODE_TX        =         USART_CR1_TE,                    /*!< TX mode        */
    UART_MODE_TX_RX     =         (USART_CR1_TE |USART_CR1_RE)    /*!< RX and TX mode */
};
enum USARTParity
{
    UART_PARITY_NONE    =       0x00000000U,                        /*!< No parity   */
    UART_PARITY_EVEN    =       USART_CR1_PCE,                      /*!< Even parity */
    UART_PARITY_ODD     =       (USART_CR1_PCE | USART_CR1_PS)     /*!< Odd parity  */
};
enum USARTHwCtrl
{
    UART_HWCONTROL_NONE       =        0x00000000U,                          /*!< No hardware control       */
    UART_HWCONTROL_RTS        =        USART_CR3_RTSE,                       /*!< Request To Send           */
    UART_HWCONTROL_CTS        =        USART_CR3_CTSE,                       /*!< Clear To Send             */
    UART_HWCONTROL_RTS_CTS    =        (USART_CR3_RTSE | USART_CR3_CTSE)    /*!< Request and Clear To Send */
};
enum USARTState
{
    UART_STATE_PARITY_ERROR = USART_ISR_PE,
    UART_STATE_FRAME_ERROR = USART_ISR_FE,
    UART_STATE_NOISE_ERROR = USART_ISR_NE,
    UART_STATE_OVERRUN_ERROR = USART_ISR_ORE,
    UART_STATE_IDLE_LINE_FREE_FLAG = USART_ISR_IDLE,
    UART_STATE_RX_REG_OR_RFIFO_NOT_EMPTY = USART_ISR_RXNE_RXFNE,
    UART_STATE_TRANSMIT_COMPLETE = USART_ISR_TC,
    UART_STATE_TX_REG_OR_TFIFO_NOT_FULL = USART_ISR_TXE_TXFNF,
    UART_STATE_LINBREAK = USART_ISR_LBDF,
    UART_STATE_CTS_CHANGE = USART_ISR_CTSIF,
    UART_STATE_CTS_FLAG = USART_ISR_CTS,
    UART_STATE_RECV_TIMEOUT = USART_ISR_RTOF,
    UART_STATE_END_OF_BLOCK = USART_ISR_EOBF,
    UART_STATE_SLAVE_UNDERRUN_ERROR = USART_ISR_UDR,
    UART_STATE_AUTO_BAUD_RATE_ERROR = USART_ISR_ABRE,
    UART_STATE_AUTO_BAUD_RATE_FLAG = USART_ISR_ABRF,
    UART_STATE_RX_BUSY = USART_ISR_BUSY,
    UART_STATE_CHR_MATCH_FLAG = USART_ISR_CMF,
    UART_STATE_SEND_BREAK_FLAG = USART_ISR_SBKF,
    UART_STATE_RECV_WAKEUP_FROM_MUTE = USART_ISR_RWU,
    UART_STATE_WAKEUP_FROM_LOWPOWER_MODE = USART_ISR_WUF,
    UART_STATE_TRANSEMIT_ENABLE_FLAG = USART_ISR_TEACK,
    UART_STATE_RECV_ENABLE_FLAG = USART_ISR_REACK,
    UART_STATE_TXFIFO_EMPTY = USART_ISR_TXFE,
    UART_STATE_RXFIFO_FULL = USART_ISR_RXFF,
    UART_STATE_TRANSMIT_COMPLETE_BEFOR_GUARD_TIME = USART_ISR_TCBGT,
    UART_STATE_RX_THRESHOLD_FLAG = USART_ISR_RXFT,
    UART_STATE_TX_THRESHOLD_FLAG = USART_ISR_TXFT
};
enum USARTStateClean
{
    UART_CLEAN_PARITY_ERROR = USART_ICR_PECF,
    UART_CLEAN_FRAME_ERROR = USART_ICR_FECF,
    UART_CLEAN_NOISE_ERROR = USART_ICR_NECF,
    UART_CLEAN_OVERRUN_ERROR = USART_ICR_ORECF,
    UART_CLEAN_IDLE_LINE_FREE_FLAG = USART_ICR_IDLECF,
    UART_CLEAN_TX_FIFO_EMPTY_FLAG = USART_ICR_TXFECF,
    UART_CLEAN_TRANSMIT_COMPLETE_FLAG = USART_ICR_TCCF,
    UART_CLEAN_TRANSMIT_COMPLETE_BEFOR_GUARD_TIME = USART_ICR_TCBGTCF,
    UART_CLEAN_LINBREAK_FLAG = USART_ICR_LBDCF,
    UART_CLEAN_CTS_CHANGE_FLAG = USART_ICR_CTSCF,
    UART_CLEAN_RECV_TIMEOUT_FLAG = USART_ICR_RTOCF,
    UART_CLEAN_END_OF_BLOCK_FLAG = USART_ICR_EOBCF,
    UART_CLEAN_SLAVE_UNDERRUN_ERROR = USART_ICR_UDRCF,
    UART_CLEAN_CHR_MATCH_FLAG = USART_ICR_CMCF,
    UART_CLEAN_WAKEUP_FROM_LOWPOWER_MODE = USART_ICR_WUCF
};
enum USARTErrorState
{
    UART_ERR_PARITY_ERROR = UART_STATE_PARITY_ERROR,
    UART_ERR_FRAME_ERROR = UART_STATE_FRAME_ERROR,
    UART_ERR_NOISE_ERROR = UART_STATE_NOISE_ERROR,
    UART_ERR_OVERRUN_ERROR = UART_STATE_OVERRUN_ERROR,
    UART_ERR_SLAVE_UNDERRUN_ERROR = UART_STATE_SLAVE_UNDERRUN_ERROR,
    UART_ERR_AUTO_BAUD_RATE_ERROR = UART_STATE_AUTO_BAUD_RATE_ERROR
};
class USART
{
    using USARTInterruptCb = std::function<void(USART*, uint32_t, uint32_t)>;
public:
    USART(USART_TypeDef *uartx, uint32_t bound, USARTMode mode, USARTWordLen wordLen = UART_WORDLENGTH_8B, 
                USARTStopBit stopBit = UART_STOPBITS_1, USARTParity parity = UART_PARITY_NONE, USARTHwCtrl hwctrl = UART_HWCONTROL_NONE) : uartx_(uartx)
    {
        enableClock(true);
        init(getClock(), bound, mode, wordLen ,stopBit,  parity ,  hwctrl);
        enable(true);
    }
    ~USART()
    {
    }
    USART(const USART&) = delete;
    USART(USART&&) = delete;
    USART& operator=(const USART&) = delete;
    USART& operator=(USART&&) = delete;
    uint32_t getState()
    {
        return uartx_->ISR;
    }
    void cleanStatus(uint32_t sta)
    {
        SET_BIT(uartx_->ICR, sta);
    }
    bool isEnable()
    {
        return (uartx_->CR1 & USART_CR1_UE);
    }
    void enable(bool benable)
    {
        if(benable)
        {
            SET_BIT(uartx_->CR1, USART_CR1_UE);
        }
        else
        {
            CLEAR_BIT(uartx_->CR1, USART_CR1_UE);
        }
    }
    bool enableFIFO(bool benable)
    {
        if(READ_BIT(uartx_->CR1, USART_CR1_UE))
        {
            return false;
        }
        if(benable)
        {
            SET_BIT(uartx_->CR1, USART_CR1_FIFOEN);
        }
        else
        {
            CLEAR_BIT(uartx_->CR1, USART_CR1_FIFOEN);
        }
        return true;
    }
    bool enableTxFIFOEmptyIsr(bool benable)
    {
        if(benable)
        {
            if(!READ_BIT(uartx_->CR1, USART_CR1_FIFOEN))
            {
                return false;
            }
            SET_BIT(uartx_->CR1, USART_CR1_TXFEIE);
        }
        else
        {
            CLEAR_BIT(uartx_->CR1, USART_CR1_TXFEIE);
        }
        return true;
    }
    bool enableRxFIFOFullIsr(bool benable)
    {
        if(benable)
        {
            if(!READ_BIT(uartx_->CR1, USART_CR1_FIFOEN))
            {
                return false;
            }
            SET_BIT(uartx_->CR1, USART_CR1_RXFFIE);
        }
        else
        {
            CLEAR_BIT(uartx_->CR1, USART_CR1_RXFFIE);
        }
        return true;
    }
    void enableLowPowerMode(bool benable)
    {
        if(benable)
        {
            SET_BIT(uartx_->CR1, USART_CR1_UESM);
        }
        else
        {
            CLEAR_BIT(uartx_->CR1, USART_CR1_UESM);
        }
    }
    void enableTX(bool benable)
    {
        if(benable)
        {
            SET_BIT(uartx_->CR1, USART_CR1_TE);
        }
        else
        {
            CLEAR_BIT(uartx_->CR1, USART_CR1_TE);
        }
    }
    void enableRX(bool benable)
    {
        if(benable)
        {
            SET_BIT(uartx_->CR1, USART_CR1_RE);
        }
        else
        {
            CLEAR_BIT(uartx_->CR1, USART_CR1_RE);
        }
    }
    void enableIDLEIsr(bool benable)
    {
        if(benable)
        {
            SET_BIT(uartx_->CR1, USART_CR1_IDLEIE);
        }
        else
        {
            CLEAR_BIT(uartx_->CR1, USART_CR1_IDLEIE);
        }
    }
    void enableRXFIFONotEmptyIsr(bool benable)
    {
        if(benable)
        {
            SET_BIT(uartx_->CR1, USART_CR1_RXNEIE_RXFNEIE);
        }
        else
        {
            CLEAR_BIT(uartx_->CR1, USART_CR1_RXNEIE_RXFNEIE);
        }
    }
    void enableTransferCompleteIsr(bool benable)
    {
        if(benable)
        {
            SET_BIT(uartx_->CR1, USART_CR1_TCIE);
        }
        else
        {
            CLEAR_BIT(uartx_->CR1, USART_CR1_TCIE);
        }
    }
    void enableTXRegisterEmptyOrTXFIFONotFullIsr(bool benable)
    {
        if(benable)
        {
            SET_BIT(uartx_->CR1, USART_CR1_TXEIE_TXFNFIE);
        }
        else
        {
            CLEAR_BIT(uartx_->CR1, USART_CR1_TXEIE_TXFNFIE);
        }
    }
    void enablePEIsr(bool benable)/*奇偶校验错误*/
    {
        if(benable)
        {
            SET_BIT(uartx_->CR1, USART_CR1_PEIE);
        }
        else
        {
            CLEAR_BIT(uartx_->CR1, USART_CR1_PEIE);
        }
    }
    void enableCharacterMatchIsr(bool benable) /*字符怕匹配中断*/
    {
        if(benable)
        {
            SET_BIT(uartx_->CR1, USART_CR1_CMIE);
        }
        else
        {
            CLEAR_BIT(uartx_->CR1, USART_CR1_CMIE);
        }
    }
    void enableEndOfBlockIsr(bool benable)
    {
        if(benable)
        {
            SET_BIT(uartx_->CR1, USART_CR1_EOBIE);
        }
        else
        {
            CLEAR_BIT(uartx_->CR1, USART_CR1_EOBIE);
        }
    }
    bool setStopBit(USARTStopBit stopbit)
    {
        if(READ_BIT(uartx_->CR1, USART_CR1_UE))
        {
            return false;
        }
        MODIFY_REG(uartx_->CR2, USART_CR2_STOP, stopbit);
        return true;
    }
    bool swapTXRXPin(bool benable)
    {        
        if(READ_BIT(uartx_->CR1, USART_CR1_UE))
        {
            return false;
        }
        if(benable)
        {
            SET_BIT(uartx_->CR2, USART_CR2_SWAP);
        }
        else
        {
            CLEAR_BIT(uartx_->CR2, USART_CR2_SWAP);
        }
        return true;
    }
    bool enableMSBFirst(bool benable)
    {
        if(READ_BIT(uartx_->CR1, USART_CR1_UE))
        {
            return false;
        }
        if(benable)
        {
            SET_BIT(uartx_->CR2, USART_CR2_MSBFIRST);
        }
        else
        {
            CLEAR_BIT(uartx_->CR2, USART_CR2_MSBFIRST);
        }
        return true;
    }
    void enableErrIsr(bool benable)
    {
        if(benable)
        {
            SET_BIT(uartx_->CR3, USART_CR3_EIE);
        }
        else
        {
            CLEAR_BIT(uartx_->CR3, USART_CR3_EIE);
        }
    }
    bool enableHalfDuplex(bool benable)
    {
        if(READ_BIT(uartx_->CR1, USART_CR1_UE))
        {
            return false;
        }
        if(benable)
        {
            SET_BIT(uartx_->CR3, USART_CR3_HDSEL);
        }
        else
        {
            CLEAR_BIT(uartx_->CR3, USART_CR3_HDSEL);
        }
        return true;
    }
    bool enableSmartCardMode(bool benable)
    {
        if(READ_BIT(uartx_->CR1, USART_CR1_UE))
        {
            return false;
        }
        if(benable)
        {
            SET_BIT(uartx_->CR3, USART_CR3_SCEN);
        }
        else
        {
            CLEAR_BIT(uartx_->CR3, USART_CR3_SCEN);
        }
        return true;
    }
    bool enableDMAT(bool benable)
    {
        if(benable)
        {
            SET_BIT(uartx_->CR3, USART_CR3_DMAT);
        }
        else
        {
            CLEAR_BIT(uartx_->CR3, USART_CR3_DMAT);
        }
        return true;
    }
    bool enableDMAR(bool benable)
    {
        if(benable)
        {
            SET_BIT(uartx_->CR3, USART_CR3_DMAR);
        }
        else
        {
            CLEAR_BIT(uartx_->CR3, USART_CR3_DMAR);
        }
        return true;
    }
    bool enableRTS(bool benable)
    {
        if(READ_BIT(uartx_->CR1, USART_CR1_UE))
        {
            return false;
        }
        if(benable)
        {
            SET_BIT(uartx_->CR3, USART_CR3_RTSE);
        }
        else
        {
            CLEAR_BIT(uartx_->CR3, USART_CR3_RTSE);
        }
        return true;
    }
    bool enableCTS(bool benable)
    {
        if(READ_BIT(uartx_->CR1, USART_CR1_UE))
        {
            return false;
        }
        if(benable)
        {
            SET_BIT(uartx_->CR3, USART_CR3_CTSE);
        }
        else
        {
            CLEAR_BIT(uartx_->CR3, USART_CR3_CTSE);
        }
        return true;
    }
    void enableCTSInterrupt(bool benable)
    {
        if(benable)
        {
            SET_BIT(uartx_->CR3, USART_CR3_CTSIE);
        }
        else
        {
            CLEAR_BIT(uartx_->CR3, USART_CR3_CTSIE);
        }
    }
    bool setBaudRate(uint32_t baud)
    {
        if(READ_BIT(uartx_->CR1, USART_CR1_UE))
        {
            return false;
        }
        WRITE_REG(uartx_->BRR, (getClock()+baud/2)/baud);
        return true;
    }
    bool transmit(const uint8_t *pData, uint16_t* size, uint32_t timeout)
    {
        const uint8_t  *pdata8bits = nullptr;
        const uint16_t *pdata16bits = nullptr;
        uint32_t tickstart = getTick();
        uint32_t count = *size;
        if((READ_REG(uartx_->CR1) & (UART_WORDLENGTH_9B | UART_PARITY_NONE)) == (UART_WORDLENGTH_9B | UART_PARITY_NONE))
        {
            pdata8bits  = nullptr;
            pdata16bits =  reinterpret_cast<const uint16_t *>(pData);
        }
        else
        {
            pdata8bits  = pData;
            pdata16bits = nullptr;
        }
        while(count > 0U)
        {
            if(!waitOnStateUntilTimeout(UART_STATE_TX_REG_OR_TFIFO_NOT_FULL, RESET, tickstart, timeout))
            {
                return false;
            }
            if(pdata8bits == nullptr)
            {
                uartx_->TDR = (uint16_t)(*pdata16bits & (uint16_t)0x01FF);
                pdata16bits++;
            }
            else
            {
                uartx_->TDR = (uint8_t)(*pdata8bits & (uint16_t)0xFF);
                pdata8bits++;
            }
            count --;
        }
        if(!waitOnStateUntilTimeout(UART_STATE_TRANSMIT_COMPLETE, RESET, tickstart, timeout))
        {
            return false;
        }
        *size -= count;
        return true;
    }
    bool receive(uint8_t *pData, uint16_t* size, uint32_t timeout)
    {
        uint8_t  *pdata8bits;
        uint16_t *pdata16bits;
        uint32_t tickstart;
        tickstart = getTick();
        uint16_t count = *size;
        uint16_t mask = 0x00;

        if((READ_REG(uartx_->CR1) & UART_WORDLENGTH_9B) == UART_WORDLENGTH_9B)
        {
            if((READ_REG(uartx_->CR1) & UART_PARITY_NONE) == UART_PARITY_NONE)
            {
                mask = 0x01FFU;
            }
            else
            {
                mask = 0x00FFU;
            }
        }
        else if((READ_REG(uartx_->CR1) & UART_WORDLENGTH_8B) == UART_WORDLENGTH_8B)
        {
            if((READ_REG(uartx_->CR1) & UART_PARITY_NONE) == UART_PARITY_NONE)
            {
                mask = 0x00FFU;
            }
            else
            {
                mask = 0x007FU;
            }
        }
        else if((READ_REG(uartx_->CR1) & UART_WORDLENGTH_7B) == UART_WORDLENGTH_7B)
        {
            if((READ_REG(uartx_->CR1) & UART_PARITY_NONE) == UART_PARITY_NONE)
            {
                mask = 0x007FU;
            }
            else
            {
                mask = 0x003FU;
            }
        }
        else
        {
            mask = 0x0000U;
        }
        if((READ_REG(uartx_->CR1) & (UART_WORDLENGTH_9B | UART_PARITY_NONE)) == (UART_WORDLENGTH_9B | UART_PARITY_NONE))
        {
            pdata8bits  = nullptr;
            pdata16bits =  reinterpret_cast<uint16_t *>(pData);
        }
        else
        {
            pdata8bits  = pData;
            pdata16bits = nullptr;
        }
        while(count > 0)
        {
            if(!waitOnStateUntilTimeout(UART_STATE_RX_REG_OR_RFIFO_NOT_EMPTY, RESET, tickstart, timeout))
            {
                return false;
            }
            if(pdata8bits == nullptr)
            {
                *pdata16bits = (uint16_t)(uartx_->RDR & mask);
                pdata16bits++;
            }
            else
            {
                *pdata8bits = (uint8_t)(uartx_->RDR & (uint8_t)mask);
                pdata8bits++;
            }
            count --;
        }
        *size -= count;
        return true;
    }
    /*USART_TypeDef * getUart()
    {
        return uartx_;
    }*/
    void registerInterruptCb(const USARTInterruptCb& isrcb)
    {
        isrcb_ = isrcb;
    }
    void unregisterInterruptCb()
    {
        if(isrcb_)
        {
            isrcb_ = USARTInterruptCb();
        }
    }
    void setNvicPriority(uint32_t PreemptPriority, uint32_t SubPriority)
    {
        uint32_t prioritygroup;
        prioritygroup = NVIC_GetPriorityGrouping();
        NVIC_SetPriority(irqType_, NVIC_EncodePriority(prioritygroup, PreemptPriority, SubPriority));
    }
    void enableNVICIrq()
    {
        NVIC_EnableIRQ(irqType_);
    }
    void disableNVICIrq()
    {
        NVIC_DisableIRQ(irqType_);
    }
private:
    bool init(uint32_t clock, uint32_t bound, USARTMode mode, USARTWordLen wordLen = UART_WORDLENGTH_8B, 
                USARTStopBit stopBit = UART_STOPBITS_1, USARTParity parity = UART_PARITY_NONE, USARTHwCtrl hwctrl = UART_HWCONTROL_NONE)
    {
        if(!uartx_)
        {
            return false;
        }
	    uint32_t temp = 0;	   
	    temp = (clock+bound/2)/bound;	//得到USARTDIV@OVER8=0,采用四舍五入计算
        //波特率设置
        uartx_->BRR = temp; 		//波特率设置@OVER8=0 	
        CLEAR_REG(uartx_->CR1);     //清零CR1寄存器	 	
        uartx_->CR1 |= wordLen;	 	//设置M1=0
        uartx_->CR1 |= wordLen;	 	//设置M0=0&M1=0,选择8位字长 
        uartx_->CR1 |= UART_OVERSAMPLING_16; 	    //设置OVER8=0,16倍过采样 
        uartx_->CR1 |= parity;      //奇偶校验使能
        uartx_->CR1 |= mode;  	    //串口rx/tx mode 

        CLEAR_REG(uartx_->CR2);     //清零CR2寄存器
        uartx_->CR2|=stopBit;
        uartx_->CR2|=stopBit;

        CLEAR_REG(uartx_->CR3);     //清零CR3寄存器
        uartx_->CR3 |= hwctrl;
        irqType_ = getIrqType();

        registerUsartIsrCb(uartx_, [](USART_TypeDef *uartx, void* param){
            USART* pusart = reinterpret_cast<USART*>(param);
            uint32_t errStates = pusart->uartx_->ISR & (UART_ERR_PARITY_ERROR | UART_ERR_FRAME_ERROR | UART_ERR_NOISE_ERROR | UART_ERR_OVERRUN_ERROR | UART_ERR_SLAVE_UNDERRUN_ERROR | UART_ERR_AUTO_BAUD_RATE_ERROR);
            if(pusart->isrcb_)
            {
                pusart->isrcb_(pusart, pusart->getState(), errStates);
            }
            if(errStates)
            {
                SET_BIT(pusart->uartx_->ICR, UART_CLEAN_PARITY_ERROR | UART_CLEAN_FRAME_ERROR | UART_CLEAN_NOISE_ERROR | UART_CLEAN_OVERRUN_ERROR |UART_CLEAN_SLAVE_UNDERRUN_ERROR);
            }
        }, this);
        return true;
    }
    void deinit()
    {
        enable(false);
        enableClock(false);
        CLEAR_REG(uartx_->CR1);
        CLEAR_REG(uartx_->CR2);
        CLEAR_REG(uartx_->CR3);
        //usartxIsrCallback();
    }
    bool waitOnStateUntilTimeout(USARTState flag, FlagStatus status, uint32_t tickstart, uint32_t timeout)
    {
        while(((getState() & flag) ? SET : RESET) == status)
        {
            if(timeout != MAX_DELAY)
            {
                if(((getTick() - tickstart) > timeout) || (timeout == 0U))
                {
                    ATOMIC_CLEAR_BIT(uartx_->CR1, (USART_CR1_RXNEIE_RXFNEIE | USART_CR1_PEIE |
                                                USART_CR1_TXEIE_TXFNFIE));
                    ATOMIC_CLEAR_BIT(uartx_->CR3, USART_CR3_EIE);

                    return false;
                }
                if(READ_BIT(uartx_->CR1, USART_CR1_RE))
                {
                    if(getState() & UART_STATE_RECV_TIMEOUT)
                    {
                        cleanStatus(UART_CLEAN_RECV_TIMEOUT_FLAG);
                        /* Disable TXE, RXNE, PE and ERR (Frame error, noise error, overrun error)
                        interrupts for the interrupt process */
                        ATOMIC_CLEAR_BIT(uartx_->CR1, (USART_CR1_RXNEIE_RXFNEIE | USART_CR1_PEIE |
                                                USART_CR1_TXEIE_TXFNFIE));
                        ATOMIC_CLEAR_BIT(uartx_->CR3, USART_CR3_EIE);
                        return false;
                    }
                }
            }
        }
        return true;
    }
    void enableClock(bool benable)
    {
        uint32_t uartaddr = reinterpret_cast<uint32_t> (uartx_);
        switch(uartaddr)
        {
            case USART1_BASE:
                if(benable)
                {
                    RCCControl::getInstance()->APB2GRP1EnableClock(RCC_APB2_GRP1_PERIPH_USART1);
                }
                else
                {
                    RCCControl::getInstance()->APB2GRP1DisableClock(RCC_APB2_GRP1_PERIPH_USART1);
                }
            break;
            case USART2_BASE:
                if(benable)
                {
                    RCCControl::getInstance()->APB1GRP1EnableClock(RCC_APB1_GRP1_PERIPH_USART2);
                }
                else
                {
                    RCCControl::getInstance()->APB1GRP1DisableClock(RCC_APB1_GRP1_PERIPH_USART2);
                }
            break;
            case USART3_BASE:
                if(benable)
                {
                    RCCControl::getInstance()->APB1GRP1EnableClock(RCC_APB1_GRP1_PERIPH_USART3);
                }
                else
                {
                    RCCControl::getInstance()->APB1GRP1DisableClock(RCC_APB1_GRP1_PERIPH_USART3);
                }
            break;
            case UART4_BASE:
                if(benable)
                {
                    RCCControl::getInstance()->APB1GRP1EnableClock(RCC_APB1_GRP1_PERIPH_UART4);
                }
                else
                {
                    RCCControl::getInstance()->APB1GRP1DisableClock(RCC_APB1_GRP1_PERIPH_UART4);
                }
            break;
            case UART5_BASE:
                if(benable)
                {
                    RCCControl::getInstance()->APB1GRP1EnableClock(RCC_APB1_GRP1_PERIPH_UART5);
                }
                else
                {
                    RCCControl::getInstance()->APB1GRP1DisableClock(RCC_APB1_GRP1_PERIPH_UART5);
                }
            break;
            case USART6_BASE:
                if(benable)
                {
                    RCCControl::getInstance()->APB2GRP1EnableClock(RCC_APB2_GRP1_PERIPH_USART6);
                }
                else
                {
                    RCCControl::getInstance()->APB2GRP1DisableClock(RCC_APB2_GRP1_PERIPH_USART6);
                }
            break;
            case UART7_BASE:
                if(benable)
                {
                    RCCControl::getInstance()->APB1GRP1EnableClock(RCC_APB1_GRP1_PERIPH_UART7);
                }
                else
                {
                    RCCControl::getInstance()->APB1GRP1DisableClock(RCC_APB1_GRP1_PERIPH_UART7);
                }
            break;
            case UART8_BASE:
                if(benable)
                {
                    RCCControl::getInstance()->APB1GRP1EnableClock(RCC_APB1_GRP1_PERIPH_UART8);
                }
                else
                {
                    RCCControl::getInstance()->APB1GRP1DisableClock(RCC_APB1_GRP1_PERIPH_UART8);
                }
            break;
            default:
            break;
        }
    }
    IRQn_Type getIrqType()
    {
        IRQn_Type irqType = USART1_IRQn;
        uint32_t uartaddr = reinterpret_cast<uint32_t> (uartx_);
        switch(uartaddr)
        {
            case USART1_BASE:
            {
                irqType = USART1_IRQn;
            }
            break;
            case USART2_BASE:
            {
                irqType = USART2_IRQn;
            }
            break;
            case USART3_BASE:
            {
                irqType = USART3_IRQn;
            }
            break;
            case UART4_BASE:
            {
                irqType = UART4_IRQn;
            }
            break;
            case UART5_BASE:
            {
                irqType = UART5_IRQn;
            }
            break;
            case USART6_BASE:
            {
                irqType = USART6_IRQn;
            }
            break;
            case UART7_BASE:
            {
                irqType = UART7_IRQn;
            }
            break;
            case UART8_BASE:
            {
                irqType = UART8_IRQn;
            }
            break;
            default:
            break;
        }
        return irqType;
    }
    uint32_t getClock()
    {
        uint32_t uartaddr = reinterpret_cast<uint32_t> (uartx_);
        uint32_t clk = 0;
        switch(uartaddr)
        {
            case USART1_BASE:
            case USART6_BASE:
                    clk = RCCControl::getInstance()->GetUSARTClockFreq(RCC_USART16_CLKSOURCE);
                break;
            case USART2_BASE:
            case USART3_BASE:
            case UART4_BASE:
            case UART5_BASE:
            case UART7_BASE:
            case UART8_BASE:
                    clk = RCCControl::getInstance()->GetUSARTClockFreq(RCC_USART234578_CLKSOURCE);
                break;
            default:
            break;
        }
        return clk;
    }
private:
    USART_TypeDef *uartx_;
    USARTInterruptCb isrcb_;
    IRQn_Type irqType_;
    //uint8_t usartRxBuff_[256];
    //uint16_t usartRxState_;
};
