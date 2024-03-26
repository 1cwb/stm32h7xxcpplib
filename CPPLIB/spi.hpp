#pragma once
#include "common.hpp"
#include <functional>
/**
  * @brief  SPI Init structures definition
  */
struct SPIInitTypeDef
{
  uint32_t TransferDirection;       /*!< Specifies the SPI unidirectional or bidirectional data mode.
                                         This parameter can be a value of @ref SPI_LL_EC_TRANSFER_MODE.

                                         This feature can be modified afterwards using unitary function
                                         @ref spiSetTransferDirection().*/

  uint32_t Mode;                    /*!< Specifies the SPI mode (Master/Slave).
                                         This parameter can be a value of @ref SPI_LL_EC_MODE.

                                         This feature can be modified afterwards using unitary function
                                         @ref spiSetMode().*/

  uint32_t DataWidth;               /*!< Specifies the SPI data width.
                                         This parameter can be a value of @ref SPI_LL_EC_DATAWIDTH.

                                         This feature can be modified afterwards using unitary function
                                         @ref spiSetDataWidth().*/

  uint32_t ClockPolarity;           /*!< Specifies the serial clock steady state.
                                         This parameter can be a value of @ref SPI_LL_EC_POLARITY.

                                         This feature can be modified afterwards using unitary function
                                         @ref spiSetClockPolarity().*/

  uint32_t ClockPhase;              /*!< Specifies the clock active edge for the bit capture.
                                         This parameter can be a value of @ref SPI_LL_EC_PHASE.

                                         This feature can be modified afterwards using unitary function
                                         @ref spiSetClockPhase().*/

  uint32_t NSS;                     /*!< Specifies whether the NSS signal is managed by hardware (NSS pin)
                                         or by software using the SSI bit.

                                         This parameter can be a value of @ref SPI_LL_EC_NSS_MODE.

                                         This feature can be modified afterwards using unitary function
                                         @ref spiSetNSSMode().*/

  uint32_t BaudRate;                /*!< Specifies the BaudRate prescaler value which will be used to configure
                                         the transmit and receive SCK clock.
                                         This parameter can be a value of @ref SPI_LL_EC_BAUDRATEPRESCALER.
                                         @note The communication clock is derived from the master clock.
                                         The slave clock does not need to be set.

                                         This feature can be modified afterwards using unitary function
                                         @ref spiSetBaudRatePrescaler().*/

  uint32_t BitOrder;                /*!< Specifies whether data transfers start from MSB or LSB bit.
                                         This parameter can be a value of @ref SPI_LL_EC_BITORDER.

                                         This feature can be modified afterwards using unitary function
                                         @ref spiSetTransferBitOrder().*/

  uint32_t CRCCalculation;          /*!< Specifies if the CRC calculation is enabled or not.
                                         This parameter can be a value of @ref SPI_LL_EC_CRC_CALCULATION.

                                         This feature can be modified afterwards using unitary functions
                                         @ref spiEnableCRC() and @ref spiDisableCRC().*/

  uint32_t CRCPoly;                 /*!< Specifies the polynomial used for the CRC calculation.
                                         This parameter must be a number between Min_Data = 0x00
                                         and Max_Data = 0xFFFFFFFF.

                                         This feature can be modified afterwards using unitary function
                                         @ref spiSetCRCPolynomial().*/

};

/* Exported types ------------------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/
/** @defgroup SPI_LL_Exported_Constants SPI Exported Constants
  * @{
  */

/** @defgroup SPI_LL_EC_MODE Mode
  * @{
  */
enum SPIMode
{
    M_SPI_MODE_MASTER        =                 (SPI_CFG2_MASTER),
    M_SPI_MODE_SLAVE         =                 (0x00000000UL),
};

/** @defgroup SPI_LL_EC_SS_LEVEL SS Level
  * @{
  */
enum SPISSLevel
{
    M_SPI_SS_LEVEL_HIGH      =                 (SPI_CR1_SSI),
    M_SPI_SS_LEVEL_LOW       =                 (0x00000000UL),
};

/** @defgroup SPI_LL_EC_SS_IDLENESS SS Idleness
  * @{
  */
enum SPISSIdleNess
{
    M_SPI_SS_IDLENESS_00CYCLE      =          (0x00000000UL),
    M_SPI_SS_IDLENESS_01CYCLE      =          (SPI_CFG2_MSSI_0),
    M_SPI_SS_IDLENESS_02CYCLE      =          (SPI_CFG2_MSSI_1),
    M_SPI_SS_IDLENESS_03CYCLE      =          (SPI_CFG2_MSSI_0 | SPI_CFG2_MSSI_1),
    M_SPI_SS_IDLENESS_04CYCLE      =          (SPI_CFG2_MSSI_2),
    M_SPI_SS_IDLENESS_05CYCLE      =          (SPI_CFG2_MSSI_2 | SPI_CFG2_MSSI_0),
    M_SPI_SS_IDLENESS_06CYCLE      =          (SPI_CFG2_MSSI_2 | SPI_CFG2_MSSI_1),
    M_SPI_SS_IDLENESS_07CYCLE      =          (SPI_CFG2_MSSI_2 | SPI_CFG2_MSSI_1 | SPI_CFG2_MSSI_0),
    M_SPI_SS_IDLENESS_08CYCLE      =          (SPI_CFG2_MSSI_3),
    M_SPI_SS_IDLENESS_09CYCLE      =          (SPI_CFG2_MSSI_3 | SPI_CFG2_MSSI_0),
    M_SPI_SS_IDLENESS_10CYCLE      =          (SPI_CFG2_MSSI_3 | SPI_CFG2_MSSI_1),
    M_SPI_SS_IDLENESS_11CYCLE      =          (SPI_CFG2_MSSI_3 | SPI_CFG2_MSSI_1 | SPI_CFG2_MSSI_0),
    M_SPI_SS_IDLENESS_12CYCLE      =          (SPI_CFG2_MSSI_3 | SPI_CFG2_MSSI_2),
    M_SPI_SS_IDLENESS_13CYCLE      =          (SPI_CFG2_MSSI_3 | SPI_CFG2_MSSI_2 | SPI_CFG2_MSSI_0),
    M_SPI_SS_IDLENESS_14CYCLE      =          (SPI_CFG2_MSSI_3 | SPI_CFG2_MSSI_2 | SPI_CFG2_MSSI_1),
    M_SPI_SS_IDLENESS_15CYCLE      =          (SPI_CFG2_MSSI_3\
                                                        | SPI_CFG2_MSSI_2 | SPI_CFG2_MSSI_1 | SPI_CFG2_MSSI_0),
};

/** @defgroup SPI_LL_EC_ID_IDLENESS Master Inter-Data Idleness
  * @{
  */
enum SPIIDIdleNess
{
    M_SPI_ID_IDLENESS_00CYCLE       =          (0x00000000UL),
    M_SPI_ID_IDLENESS_01CYCLE       =          (SPI_CFG2_MIDI_0),
    M_SPI_ID_IDLENESS_02CYCLE       =          (SPI_CFG2_MIDI_1),
    M_SPI_ID_IDLENESS_03CYCLE       =          (SPI_CFG2_MIDI_0 | SPI_CFG2_MIDI_1),
    M_SPI_ID_IDLENESS_04CYCLE       =          (SPI_CFG2_MIDI_2),
    M_SPI_ID_IDLENESS_05CYCLE       =          (SPI_CFG2_MIDI_2 | SPI_CFG2_MIDI_0),
    M_SPI_ID_IDLENESS_06CYCLE       =          (SPI_CFG2_MIDI_2 | SPI_CFG2_MIDI_1),
    M_SPI_ID_IDLENESS_07CYCLE       =          (SPI_CFG2_MIDI_2 | SPI_CFG2_MIDI_1 | SPI_CFG2_MIDI_0),
    M_SPI_ID_IDLENESS_08CYCLE       =          (SPI_CFG2_MIDI_3),
    M_SPI_ID_IDLENESS_09CYCLE       =          (SPI_CFG2_MIDI_3 | SPI_CFG2_MIDI_0),
    M_SPI_ID_IDLENESS_10CYCLE       =          (SPI_CFG2_MIDI_3 | SPI_CFG2_MIDI_1),
    M_SPI_ID_IDLENESS_11CYCLE       =          (SPI_CFG2_MIDI_3 | SPI_CFG2_MIDI_1 | SPI_CFG2_MIDI_0),
    M_SPI_ID_IDLENESS_12CYCLE       =          (SPI_CFG2_MIDI_3 | SPI_CFG2_MIDI_2),
    M_SPI_ID_IDLENESS_13CYCLE       =          (SPI_CFG2_MIDI_3 | SPI_CFG2_MIDI_2 | SPI_CFG2_MIDI_0),
    M_SPI_ID_IDLENESS_14CYCLE       =          (SPI_CFG2_MIDI_3 | SPI_CFG2_MIDI_2 | SPI_CFG2_MIDI_1),
    M_SPI_ID_IDLENESS_15CYCLE       =          (SPI_CFG2_MIDI_3\
                                                        | SPI_CFG2_MIDI_2 | SPI_CFG2_MIDI_1 | SPI_CFG2_MIDI_0),
};

/** @defgroup SPI_LL_EC_TXCRCINITALL TXCRC Init All
  * @{
  */
enum SPITXCRCInitAll
{
    M_SPI_TXCRCINITALL_ZERO_PATTERN    =      (0x00000000UL),
    M_SPI_TXCRCINITALL_ONES_PATTERN    =      (SPI_CR1_TCRCINI),
};

/** @defgroup SPI_LL_EC_RXCRCINITALL RXCRC Init All
  * @{
  */
enum SPIRXCRCInitAll
{
    M_SPI_RXCRCINITALL_ZERO_PATTERN    =      (0x00000000UL),
    M_SPI_RXCRCINITALL_ONES_PATTERN    =      (SPI_CR1_RCRCINI),
};

/** @defgroup SPI_LL_EC_UDR_CONFIG_REGISTER UDR Config Register
  * @{
  */
enum SPIUDRConfig
{
    M_SPI_UDR_CONFIG_REGISTER_PATTERN    =     (0x00000000UL),
    M_SPI_UDR_CONFIG_LAST_RECEIVED       =     (SPI_CFG1_UDRCFG_0),
    M_SPI_UDR_CONFIG_LAST_TRANSMITTED    =     (SPI_CFG1_UDRCFG_1),
};

/** @defgroup SPI_LL_EC_UDR_DETECT_BEGIN_DATA UDR Detect Begin Data
  * @{
  */
enum SPIUDRDetect
{
    M_SPI_UDR_DETECT_BEGIN_DATA_FRAME    =     (0x00000000UL),
    M_SPI_UDR_DETECT_END_DATA_FRAME      =     (SPI_CFG1_UDRDET_0),
    M_SPI_UDR_DETECT_BEGIN_ACTIVE_NSS    =     (SPI_CFG1_UDRDET_1),
};

/** @defgroup SPI_LL_EC_PROTOCOL Protocol
  * @{
  */
enum SPIProtocol
{
    M_SPI_PROTOCOL_MOTOROLA       =            (0x00000000UL),
    M_SPI_PROTOCOL_TI             =            (SPI_CFG2_SP_0),
};

/** @defgroup SPI_LL_EC_PHASE Phase
  * @{
  */
enum SPIPhase
{
    M_SPI_PHASE_1EDGE            =             (0x00000000UL),
    M_SPI_PHASE_2EDGE            =             (SPI_CFG2_CPHA),
};

/** @defgroup SPI_LL_EC_POLARITY Polarity
  * @{
  */
enum SPIPolarity
{
    M_SPI_POLARITY_LOW                =        (0x00000000UL),
    M_SPI_POLARITY_HIGH               =        (SPI_CFG2_CPOL),
};

/** @defgroup SPI_LL_EC_NSS_POLARITY NSS Polarity
  * @{
  */
enum SPINssPolarity
{
    M_SPI_NSS_POLARITY_LOW            =        (0x00000000UL),
    M_SPI_NSS_POLARITY_HIGH           =        (SPI_CFG2_SSIOP),
};

/** @defgroup SPI_LL_EC_BAUDRATEPRESCALER Baud Rate Prescaler
  * @{
  */
enum SPIBaudRatePrescaler
{
    M_SPI_BAUDRATEPRESCALER_DIV2        =      (0x00000000UL),
    M_SPI_BAUDRATEPRESCALER_DIV4        =      (SPI_CFG1_MBR_0),
    M_SPI_BAUDRATEPRESCALER_DIV8        =      (SPI_CFG1_MBR_1),
    M_SPI_BAUDRATEPRESCALER_DIV16       =      (SPI_CFG1_MBR_1 | SPI_CFG1_MBR_0),
    M_SPI_BAUDRATEPRESCALER_DIV32       =      (SPI_CFG1_MBR_2),
    M_SPI_BAUDRATEPRESCALER_DIV64       =      (SPI_CFG1_MBR_2 | SPI_CFG1_MBR_0),
    M_SPI_BAUDRATEPRESCALER_DIV128      =      (SPI_CFG1_MBR_2 | SPI_CFG1_MBR_1),
    M_SPI_BAUDRATEPRESCALER_DIV256      =      (SPI_CFG1_MBR_2 | SPI_CFG1_MBR_1 | SPI_CFG1_MBR_0),
};

/** @defgroup SPI_LL_EC_BITORDER Bit Order
  * @{
  */
enum SPIBitOrder
{
    M_SPI_LSB_FIRST            =               (SPI_CFG2_LSBFRST),
    M_SPI_MSB_FIRST            =               (0x00000000UL),
};

/** @defgroup SPI_LL_EC_TRANSFER_MODE Transfer Mode
  * @{
  */
enum SPITransferMode
{
    M_SPI_FULL_DUPLEX             =            (0x00000000UL),
    M_SPI_SIMPLEX_TX              =            (SPI_CFG2_COMM_0),
    M_SPI_SIMPLEX_RX              =            (SPI_CFG2_COMM_1),
    M_SPI_HALF_DUPLEX_RX          =            (SPI_CFG2_COMM_0|SPI_CFG2_COMM_1),
    M_SPI_HALF_DUPLEX_TX          =            (SPI_CFG2_COMM_0|SPI_CFG2_COMM_1|SPI_CR1_HDDIR),
};

/** @defgroup SPI_LL_EC_DATAWIDTH Data Width
  * @{
  */
enum SPIDataWidth
{
    M_SPI_DATAWIDTH_4BIT           =           (SPI_CFG1_DSIZE_0 | SPI_CFG1_DSIZE_1),
    M_SPI_DATAWIDTH_5BIT           =           (SPI_CFG1_DSIZE_2),
    M_SPI_DATAWIDTH_6BIT           =           (SPI_CFG1_DSIZE_2 | SPI_CFG1_DSIZE_0),
    M_SPI_DATAWIDTH_7BIT           =           (SPI_CFG1_DSIZE_2 | SPI_CFG1_DSIZE_1),
    M_SPI_DATAWIDTH_8BIT           =           (SPI_CFG1_DSIZE_2 | SPI_CFG1_DSIZE_1 | SPI_CFG1_DSIZE_0),
    M_SPI_DATAWIDTH_9BIT           =           (SPI_CFG1_DSIZE_3),
    M_SPI_DATAWIDTH_10BIT          =           (SPI_CFG1_DSIZE_3 | SPI_CFG1_DSIZE_0),
    M_SPI_DATAWIDTH_11BIT          =           (SPI_CFG1_DSIZE_3 | SPI_CFG1_DSIZE_1),
    M_SPI_DATAWIDTH_12BIT          =           (SPI_CFG1_DSIZE_3 | SPI_CFG1_DSIZE_1 | SPI_CFG1_DSIZE_0),
    M_SPI_DATAWIDTH_13BIT          =           (SPI_CFG1_DSIZE_3 | SPI_CFG1_DSIZE_2),
    M_SPI_DATAWIDTH_14BIT          =           (SPI_CFG1_DSIZE_3 | SPI_CFG1_DSIZE_2 | SPI_CFG1_DSIZE_0),
    M_SPI_DATAWIDTH_15BIT          =           (SPI_CFG1_DSIZE_3 | SPI_CFG1_DSIZE_2 | SPI_CFG1_DSIZE_1),
    M_SPI_DATAWIDTH_16BIT          =           (SPI_CFG1_DSIZE_3\
                                                         | SPI_CFG1_DSIZE_2 | SPI_CFG1_DSIZE_1 | SPI_CFG1_DSIZE_0),
    M_SPI_DATAWIDTH_17BIT          =           (SPI_CFG1_DSIZE_4),
    M_SPI_DATAWIDTH_18BIT          =           (SPI_CFG1_DSIZE_4 | SPI_CFG1_DSIZE_0),
    M_SPI_DATAWIDTH_19BIT          =           (SPI_CFG1_DSIZE_4 | SPI_CFG1_DSIZE_1),
    M_SPI_DATAWIDTH_20BIT          =           (SPI_CFG1_DSIZE_4 | SPI_CFG1_DSIZE_0 | SPI_CFG1_DSIZE_1),
    M_SPI_DATAWIDTH_21BIT          =           (SPI_CFG1_DSIZE_4 | SPI_CFG1_DSIZE_2),
    M_SPI_DATAWIDTH_22BIT          =           (SPI_CFG1_DSIZE_4 | SPI_CFG1_DSIZE_2 | SPI_CFG1_DSIZE_0),
    M_SPI_DATAWIDTH_23BIT          =           (SPI_CFG1_DSIZE_4 | SPI_CFG1_DSIZE_2 | SPI_CFG1_DSIZE_1),
    M_SPI_DATAWIDTH_24BIT          =           (SPI_CFG1_DSIZE_4\
                                                         | SPI_CFG1_DSIZE_2 | SPI_CFG1_DSIZE_1 | SPI_CFG1_DSIZE_0),
    M_SPI_DATAWIDTH_25BIT          =           (SPI_CFG1_DSIZE_4 | SPI_CFG1_DSIZE_3),
    M_SPI_DATAWIDTH_26BIT          =           (SPI_CFG1_DSIZE_4 | SPI_CFG1_DSIZE_3 | SPI_CFG1_DSIZE_0),
    M_SPI_DATAWIDTH_27BIT          =           (SPI_CFG1_DSIZE_4 | SPI_CFG1_DSIZE_3 | SPI_CFG1_DSIZE_1),
    M_SPI_DATAWIDTH_28BIT          =           (SPI_CFG1_DSIZE_4\
                                                         | SPI_CFG1_DSIZE_3 | SPI_CFG1_DSIZE_1 | SPI_CFG1_DSIZE_0),
    M_SPI_DATAWIDTH_29BIT          =           (SPI_CFG1_DSIZE_4 | SPI_CFG1_DSIZE_3 | SPI_CFG1_DSIZE_2),
    M_SPI_DATAWIDTH_30BIT          =           (SPI_CFG1_DSIZE_4\
                                                         | SPI_CFG1_DSIZE_3 | SPI_CFG1_DSIZE_2 | SPI_CFG1_DSIZE_0),
    M_SPI_DATAWIDTH_31BIT          =           (SPI_CFG1_DSIZE_4\
                                                         | SPI_CFG1_DSIZE_3 | SPI_CFG1_DSIZE_2 | SPI_CFG1_DSIZE_1),
    M_SPI_DATAWIDTH_32BIT          =           (SPI_CFG1_DSIZE_4 | SPI_CFG1_DSIZE_3\
                                                         | SPI_CFG1_DSIZE_2 | SPI_CFG1_DSIZE_1 | SPI_CFG1_DSIZE_0),
};
/** @defgroup SPI_LL_EC_FIFO_TH FIFO Threshold
  * @{
  */
enum SPIFifoThreshold
{
    M_SPI_FIFO_TH_01DATA          =            (0x00000000UL),
    M_SPI_FIFO_TH_02DATA          =            (SPI_CFG1_FTHLV_0),
    M_SPI_FIFO_TH_03DATA          =            (SPI_CFG1_FTHLV_1),
    M_SPI_FIFO_TH_04DATA          =            (SPI_CFG1_FTHLV_0 | SPI_CFG1_FTHLV_1),
    M_SPI_FIFO_TH_05DATA          =            (SPI_CFG1_FTHLV_2),
    M_SPI_FIFO_TH_06DATA          =            (SPI_CFG1_FTHLV_2 | SPI_CFG1_FTHLV_0),
    M_SPI_FIFO_TH_07DATA          =            (SPI_CFG1_FTHLV_2 | SPI_CFG1_FTHLV_1),
    M_SPI_FIFO_TH_08DATA          =            (SPI_CFG1_FTHLV_2 | SPI_CFG1_FTHLV_1 | SPI_CFG1_FTHLV_0),
    M_SPI_FIFO_TH_09DATA          =            (SPI_CFG1_FTHLV_3),
    M_SPI_FIFO_TH_10DATA          =            (SPI_CFG1_FTHLV_3 | SPI_CFG1_FTHLV_0),
    M_SPI_FIFO_TH_11DATA          =            (SPI_CFG1_FTHLV_3 | SPI_CFG1_FTHLV_1),
    M_SPI_FIFO_TH_12DATA          =            (SPI_CFG1_FTHLV_3 | SPI_CFG1_FTHLV_1 | SPI_CFG1_FTHLV_0),
    M_SPI_FIFO_TH_13DATA          =            (SPI_CFG1_FTHLV_3 | SPI_CFG1_FTHLV_2),
    M_SPI_FIFO_TH_14DATA          =            (SPI_CFG1_FTHLV_3 | SPI_CFG1_FTHLV_2 | SPI_CFG1_FTHLV_0),
    M_SPI_FIFO_TH_15DATA          =            (SPI_CFG1_FTHLV_3 | SPI_CFG1_FTHLV_2 | SPI_CFG1_FTHLV_1),
    M_SPI_FIFO_TH_16DATA          =            (SPI_CFG1_FTHLV_3\
                                                        | SPI_CFG1_FTHLV_2 | SPI_CFG1_FTHLV_1 | SPI_CFG1_FTHLV_0),
};

/** @defgroup SPI_LL_EC_CRC_CALCULATION CRC Calculation
  * @{
  */
enum SPICRCCalculation
{
    M_SPI_CRCCALCULATION_DISABLE      =        (0x00000000UL),            /*!< CRC calculation disabled */
    M_SPI_CRCCALCULATION_ENABLE       =        (SPI_CFG1_CRCEN),          /*!< CRC calculation enabled  */
};



/** @defgroup SPI_LL_EC_CRC CRC
  * @{
  */
enum SPICrcLen
{
    M_SPI_CRC_4BIT               =             (SPI_CFG1_CRCSIZE_0 | SPI_CFG1_CRCSIZE_1),
    M_SPI_CRC_5BIT               =             (SPI_CFG1_CRCSIZE_2),
    M_SPI_CRC_6BIT               =             (SPI_CFG1_CRCSIZE_2 | SPI_CFG1_CRCSIZE_0),
    M_SPI_CRC_7BIT               =             (SPI_CFG1_CRCSIZE_2 | SPI_CFG1_CRCSIZE_1),
    M_SPI_CRC_8BIT               =             (SPI_CFG1_CRCSIZE_2 | SPI_CFG1_CRCSIZE_1 | SPI_CFG1_CRCSIZE_0),
    M_SPI_CRC_9BIT               =             (SPI_CFG1_CRCSIZE_3),
    M_SPI_CRC_10BIT              =             (SPI_CFG1_CRCSIZE_3 | SPI_CFG1_CRCSIZE_0),
    M_SPI_CRC_11BIT              =             (SPI_CFG1_CRCSIZE_3 | SPI_CFG1_CRCSIZE_1),
    M_SPI_CRC_12BIT              =             (SPI_CFG1_CRCSIZE_3 | SPI_CFG1_CRCSIZE_1 | SPI_CFG1_CRCSIZE_0),
    M_SPI_CRC_13BIT              =             (SPI_CFG1_CRCSIZE_3 | SPI_CFG1_CRCSIZE_2),
    M_SPI_CRC_14BIT              =             (SPI_CFG1_CRCSIZE_3 | SPI_CFG1_CRCSIZE_2 | SPI_CFG1_CRCSIZE_0),
    M_SPI_CRC_15BIT              =             (SPI_CFG1_CRCSIZE_3 | SPI_CFG1_CRCSIZE_2 | SPI_CFG1_CRCSIZE_1),
    M_SPI_CRC_16BIT              =             (SPI_CFG1_CRCSIZE_3\
                                                        | SPI_CFG1_CRCSIZE_2 | SPI_CFG1_CRCSIZE_1 | SPI_CFG1_CRCSIZE_0),
    M_SPI_CRC_17BIT              =             (SPI_CFG1_CRCSIZE_4),
    M_SPI_CRC_18BIT              =             (SPI_CFG1_CRCSIZE_4 | SPI_CFG1_CRCSIZE_0),
    M_SPI_CRC_19BIT              =             (SPI_CFG1_CRCSIZE_4 | SPI_CFG1_CRCSIZE_1),
    M_SPI_CRC_20BIT              =             (SPI_CFG1_CRCSIZE_4 | SPI_CFG1_CRCSIZE_0 | SPI_CFG1_CRCSIZE_1),
    M_SPI_CRC_21BIT              =             (SPI_CFG1_CRCSIZE_4 | SPI_CFG1_CRCSIZE_2),
    M_SPI_CRC_22BIT              =             (SPI_CFG1_CRCSIZE_4 | SPI_CFG1_CRCSIZE_2 | SPI_CFG1_CRCSIZE_0),
    M_SPI_CRC_23BIT              =             (SPI_CFG1_CRCSIZE_4 | SPI_CFG1_CRCSIZE_2 | SPI_CFG1_CRCSIZE_1),
    M_SPI_CRC_24BIT              =             (SPI_CFG1_CRCSIZE_4\
                                                        | SPI_CFG1_CRCSIZE_2 | SPI_CFG1_CRCSIZE_1 | SPI_CFG1_CRCSIZE_0),
    M_SPI_CRC_25BIT              =             (SPI_CFG1_CRCSIZE_4 | SPI_CFG1_CRCSIZE_3),
    M_SPI_CRC_26BIT              =             (SPI_CFG1_CRCSIZE_4 | SPI_CFG1_CRCSIZE_3 | SPI_CFG1_CRCSIZE_0),
    M_SPI_CRC_27BIT              =             (SPI_CFG1_CRCSIZE_4 | SPI_CFG1_CRCSIZE_3 | SPI_CFG1_CRCSIZE_1),
    M_SPI_CRC_28BIT              =             (SPI_CFG1_CRCSIZE_4\
                                                        | SPI_CFG1_CRCSIZE_3 | SPI_CFG1_CRCSIZE_1 | SPI_CFG1_CRCSIZE_0),
    M_SPI_CRC_29BIT              =             (SPI_CFG1_CRCSIZE_4 | SPI_CFG1_CRCSIZE_3 | SPI_CFG1_CRCSIZE_2),
    M_SPI_CRC_30BIT              =             (SPI_CFG1_CRCSIZE_4\
                                                        | SPI_CFG1_CRCSIZE_3 | SPI_CFG1_CRCSIZE_2 | SPI_CFG1_CRCSIZE_0),
    M_SPI_CRC_31BIT              =             (SPI_CFG1_CRCSIZE_4\
                                                        | SPI_CFG1_CRCSIZE_3 | SPI_CFG1_CRCSIZE_2 | SPI_CFG1_CRCSIZE_1),
    M_SPI_CRC_32BIT              =             (SPI_CFG1_CRCSIZE_4 | SPI_CFG1_CRCSIZE_3\
                                                        | SPI_CFG1_CRCSIZE_2 | SPI_CFG1_CRCSIZE_1 | SPI_CFG1_CRCSIZE_0),
};

/** @defgroup SPI_LL_EC_NSS_MODE NSS Mode
  * @{
  */
enum SPINSSMode
{
    M_SPI_NSS_SOFT                 =           (SPI_CFG2_SSM),
    M_SPI_NSS_HARD_INPUT           =           (0x00000000UL),
    M_SPI_NSS_HARD_OUTPUT          =           (SPI_CFG2_SSOE),
};
/** @defgroup SPI_LL_EC_RX_FIFO RxFIFO Packing LeVel
  * @{
  */
enum SPIRXFifoPackLevel
{
    M_SPI_RX_FIFO_0PACKET        =       (0x00000000UL),    /* 0 or multiple of 4 packet available is the RxFIFO */
    M_SPI_RX_FIFO_1PACKET        =       (SPI_SR_RXPLVL_0),
    M_SPI_RX_FIFO_2PACKET        =       (SPI_SR_RXPLVL_1),
    M_SPI_RX_FIFO_3PACKET        =       (SPI_SR_RXPLVL_1 | SPI_SR_RXPLVL_0),
};

class COMMONSPI
{
    using SPIInterruptCb = std::function<void(COMMONSPI*, SPIisrFlags)>;
public:
    COMMONSPI(SPI_TypeDef* spix) : spix_(spix)
    {
      enableClk();
    }
    ~COMMONSPI()
    {

    }
    COMMONSPI(const COMMONSPI&) = delete;
    COMMONSPI(COMMONSPI&&) = delete;
    COMMONSPI& operator=(const COMMONSPI&) = delete;
    COMMONSPI& operator=(COMMONSPI&&) = delete;

    /**
      * @brief  Enable SPI peripheral
      * @rmtoll CR1          SPE           spiEnable
      * @param  SPIx SPI Instance
      * @retval None
      */
    inline void spiEnable()
    {
      SET_BIT(spix_->CR1, SPI_CR1_SPE);
    }

    /**
      * @brief  Disable SPI peripheral
      * @note   When disabling the SPI, follow the procedure described in the Reference Manual.
      * @rmtoll CR1          SPE           spiDisable
      * @param  SPIx SPI Instance
      * @retval None
      */
    inline void spiDisable()
    {
      CLEAR_BIT(spix_->CR1, SPI_CR1_SPE);
    }

    /**
      * @brief  Check if SPI peripheral is enabled
      * @rmtoll CR1          SPE           spiIsEnabled
      * @param  SPIx SPI Instance
      * @retval State of bit (1 or 0)
      */
    inline bool spiIsEnabled()
    {
      return ((READ_BIT(spix_->CR1, SPI_CR1_SPE) == (SPI_CR1_SPE)) ? true : false);
    }

    /**
      * @brief  Swap the MOSI and MISO pin
      * @note   This configuration can not be changed when SPI is enabled.
      * @rmtoll CFG2         IOSWP         spiEnableIOSwap
      * @param  SPIx SPI Instance
      * @retval None
      */
    inline void spiEnableIOSwap()
    {
      SET_BIT(spix_->CFG2, SPI_CFG2_IOSWP);
    }

    /**
      * @brief  Restore default function for MOSI and MISO pin
      * @note   This configuration can not be changed when SPI is enabled.
      * @rmtoll CFG2         IOSWP         spiDisableIOSwap
      * @param  SPIx SPI Instance
      * @retval None
      */
    inline void spiDisableIOSwap()
    {
      CLEAR_BIT(spix_->CFG2, SPI_CFG2_IOSWP);
    }

    /**
      * @brief  Check if MOSI and MISO pin are swapped
      * @rmtoll CFG2         IOSWP         spiIsEnabledIOSwap
      * @param  SPIx SPI Instance
      * @retval State of bit (1 or 0)
      */
    inline bool spiIsEnabledIOSwap()
    {
      return ((READ_BIT(spix_->CFG2, SPI_CFG2_IOSWP) == (SPI_CFG2_IOSWP)) ? true : false);
    }

    /**
      * @brief  Enable GPIO control
      * @note   This configuration can not be changed when SPI is enabled.
      * @rmtoll CFG2         AFCNTR        spiEnableGPIOControl
      * @param  SPIx SPI Instance
      * @retval None
      */
    inline void spiEnableGPIOControl()
    {
      SET_BIT(spix_->CFG2, SPI_CFG2_AFCNTR);
    }

    /**
      * @brief  Disable GPIO control
      * @note   This configuration can not be changed when SPI is enabled.
      * @rmtoll CFG2         AFCNTR        spiDisableGPIOControl
      * @param  SPIx SPI Instance
      * @retval None
      */
    inline void spiDisableGPIOControl()
    {
      CLEAR_BIT(spix_->CFG2, SPI_CFG2_AFCNTR);
    }

    /**
      * @brief  Check if GPIO control is active
      * @rmtoll CFG2         AFCNTR        spiIsEnabledGPIOControl
      * @param  SPIx SPI Instance
      * @retval State of bit (1 or 0)
      */
    inline bool spiIsEnabledGPIOControl()
    {
      return ((READ_BIT(spix_->CFG2, SPI_CFG2_AFCNTR) == (SPI_CFG2_AFCNTR)) ? true : false);
    }

    /**
      * @brief  Set SPI Mode to Master or Slave
      * @note   This configuration can not be changed when SPI is enabled.
      * @rmtoll CFG2         MASTER        spiSetMode
      * @param  SPIx SPI Instance
      * @param  Mode This parameter can be one of the following values:
      *         @arg @ref spiMODE_MASTER
      *         @arg @ref spiMODE_SLAVE
      * @retval None
      */
    inline void spiSetMode(SPIMode Mode)
    {
      MODIFY_REG(spix_->CFG2, SPI_CFG2_MASTER, Mode);
    }

    /**
      * @brief  Get SPI Mode (Master or Slave)
      * @rmtoll CFG2         MASTER        spiGetMode
      * @param  SPIx SPI Instance
      * @retval Returned value can be one of the following values:
      *         @arg @ref spiMODE_MASTER
      *         @arg @ref spiMODE_SLAVE
      */
    inline SPIMode spiGetMode()
    {
      return (SPIMode)(READ_BIT(spix_->CFG2, SPI_CFG2_MASTER));
    }

    /**
      * @brief  Configure the Idleness applied by master between active edge of SS and first send data
      * @rmtoll CFG2         MSSI          spiSetMasterSSIdleness
      * @param  SPIx SPI Instance
      * @param  MasterSSIdleness This parameter can be one of the following values:
      *         @arg @ref spiSS_IDLENESS_00CYCLE
      *         @arg @ref spiSS_IDLENESS_01CYCLE
      *         @arg @ref spiSS_IDLENESS_02CYCLE
      *         @arg @ref spiSS_IDLENESS_03CYCLE
      *         @arg @ref spiSS_IDLENESS_04CYCLE
      *         @arg @ref spiSS_IDLENESS_05CYCLE
      *         @arg @ref spiSS_IDLENESS_06CYCLE
      *         @arg @ref spiSS_IDLENESS_07CYCLE
      *         @arg @ref spiSS_IDLENESS_08CYCLE
      *         @arg @ref spiSS_IDLENESS_09CYCLE
      *         @arg @ref spiSS_IDLENESS_10CYCLE
      *         @arg @ref spiSS_IDLENESS_11CYCLE
      *         @arg @ref spiSS_IDLENESS_12CYCLE
      *         @arg @ref spiSS_IDLENESS_13CYCLE
      *         @arg @ref spiSS_IDLENESS_14CYCLE
      *         @arg @ref spiSS_IDLENESS_15CYCLE
      * @retval None
      */
    inline void spiSetMasterSSIdleness(SPISSIdleNess MasterSSIdleness)
    {
      MODIFY_REG(spix_->CFG2, SPI_CFG2_MSSI, MasterSSIdleness);
    }

    /**
      * @brief  Get the configured Idleness applied by master
      * @rmtoll CFG2         MSSI          spiGetMasterSSIdleness
      * @param  SPIx SPI Instance
      * @retval Returned value can be one of the following values:
      *         @arg @ref spiSS_IDLENESS_00CYCLE
      *         @arg @ref spiSS_IDLENESS_01CYCLE
      *         @arg @ref spiSS_IDLENESS_02CYCLE
      *         @arg @ref spiSS_IDLENESS_03CYCLE
      *         @arg @ref spiSS_IDLENESS_04CYCLE
      *         @arg @ref spiSS_IDLENESS_05CYCLE
      *         @arg @ref spiSS_IDLENESS_06CYCLE
      *         @arg @ref spiSS_IDLENESS_07CYCLE
      *         @arg @ref spiSS_IDLENESS_08CYCLE
      *         @arg @ref spiSS_IDLENESS_09CYCLE
      *         @arg @ref spiSS_IDLENESS_10CYCLE
      *         @arg @ref spiSS_IDLENESS_11CYCLE
      *         @arg @ref spiSS_IDLENESS_12CYCLE
      *         @arg @ref spiSS_IDLENESS_13CYCLE
      *         @arg @ref spiSS_IDLENESS_14CYCLE
      *         @arg @ref spiSS_IDLENESS_15CYCLE
      */
    inline SPISSIdleNess spiGetMasterSSIdleness()
    {
      return (SPISSIdleNess)(READ_BIT(spix_->CFG2, SPI_CFG2_MSSI));
    }

    /**
      * @brief  Configure the idleness applied by master between data frame
      * @rmtoll CFG2         MIDI          spiSetInterDataIdleness
      * @param  SPIx SPI Instance
      * @param  MasterInterDataIdleness This parameter can be one of the following values:
      *         @arg @ref spiID_IDLENESS_00CYCLE
      *         @arg @ref spiID_IDLENESS_01CYCLE
      *         @arg @ref spiID_IDLENESS_02CYCLE
      *         @arg @ref spiID_IDLENESS_03CYCLE
      *         @arg @ref spiID_IDLENESS_04CYCLE
      *         @arg @ref spiID_IDLENESS_05CYCLE
      *         @arg @ref spiID_IDLENESS_06CYCLE
      *         @arg @ref spiID_IDLENESS_07CYCLE
      *         @arg @ref spiID_IDLENESS_08CYCLE
      *         @arg @ref spiID_IDLENESS_09CYCLE
      *         @arg @ref spiID_IDLENESS_10CYCLE
      *         @arg @ref spiID_IDLENESS_11CYCLE
      *         @arg @ref spiID_IDLENESS_12CYCLE
      *         @arg @ref spiID_IDLENESS_13CYCLE
      *         @arg @ref spiID_IDLENESS_14CYCLE
      *         @arg @ref spiID_IDLENESS_15CYCLE
      * @retval None
      */
    inline void spiSetInterDataIdleness(SPIIDIdleNess MasterInterDataIdleness)
    {
      MODIFY_REG(spix_->CFG2, SPI_CFG2_MIDI, MasterInterDataIdleness);
    }

    /**
      * @brief  Get the configured inter data idleness
      * @rmtoll CFG2         MIDI          spiSetInterDataIdleness
      * @param  SPIx SPI Instance
      * @retval Returned value can be one of the following values:
      *         @arg @ref spiID_IDLENESS_00CYCLE
      *         @arg @ref spiID_IDLENESS_01CYCLE
      *         @arg @ref spiID_IDLENESS_02CYCLE
      *         @arg @ref spiID_IDLENESS_03CYCLE
      *         @arg @ref spiID_IDLENESS_04CYCLE
      *         @arg @ref spiID_IDLENESS_05CYCLE
      *         @arg @ref spiID_IDLENESS_06CYCLE
      *         @arg @ref spiID_IDLENESS_07CYCLE
      *         @arg @ref spiID_IDLENESS_08CYCLE
      *         @arg @ref spiID_IDLENESS_09CYCLE
      *         @arg @ref spiID_IDLENESS_10CYCLE
      *         @arg @ref spiID_IDLENESS_11CYCLE
      *         @arg @ref spiID_IDLENESS_12CYCLE
      *         @arg @ref spiID_IDLENESS_13CYCLE
      *         @arg @ref spiID_IDLENESS_14CYCLE
      *         @arg @ref spiID_IDLENESS_15CYCLE
      */
    inline SPIIDIdleNess spiGetInterDataIdleness()
    {
      return (SPIIDIdleNess)(READ_BIT(spix_->CFG2, SPI_CFG2_MIDI));
    }

    /**
      * @brief  Set transfer size
      * @note    Count is the number of frame to be transferred
      * @rmtoll CR2          TSIZE         spiSetTransferSize
      * @param  SPIx SPI Instance
      * @param  Count 0..0xFFFF
      * @retval None
      */
    inline void spiSetTransferSize(uint32_t Count)
    {
      MODIFY_REG(spix_->CR2, SPI_CR2_TSIZE, Count);
    }

    /**
      * @brief  Get transfer size
      * @note    Count is the number of frame to be transferred
      * @rmtoll CR2          TSIZE         spiGetTransferSize
      * @param  SPIx SPI Instance
      * @retval 0..0xFFFF
      */
    inline uint32_t spiGetTransferSize()
    {
      return (uint32_t)(READ_BIT(spix_->CR2, SPI_CR2_TSIZE));
    }

    /**
      * @brief  Set reload transfer size
      * @note    Count is the number of frame to be transferred
      * @rmtoll CR2          TSER          spiSetReloadSize
      * @param  SPIx SPI Instance
      * @param  Count 0..0xFFFF
      * @retval None
      */
    inline void spiSetReloadSize(uint32_t Count)
    {
      MODIFY_REG(spix_->CR2, SPI_CR2_TSER, Count << SPI_CR2_TSER_Pos);
    }

    /**
      * @brief  Get reload transfer size
      * @note    Count is the number of frame to be transferred
      * @rmtoll CR2          TSER          spiGetReloadSize
      * @param  SPIx SPI Instance
      * @retval 0..0xFFFF
      */
    inline uint32_t spiGetReloadSize()
    {
      return (uint32_t)(READ_BIT(spix_->CR2, SPI_CR2_TSER) >> SPI_CR2_TSER_Pos);
    }

    /**
      * @brief  Lock the AF configuration of associated IOs
      * @note   Once this bit is set, the AF configuration remains locked until a hardware reset occurs.
      *         the reset of the IOLock bit is done by hardware. for that, spiDisableIOLock can not exist.
      * @rmtoll CR1          IOLOCK        spiEnableIOLock
      * @param  SPIx SPI Instance
      * @retval None
      */
    inline void spiEnableIOLock()
    {
      SET_BIT(spix_->CR1, SPI_CR1_IOLOCK);
    }

    /**
      * @brief  Check if the AF configuration is locked.
      * @rmtoll CR1          IOLOCK        spiIsEnabledIOLock
      * @param  SPIx SPI Instance
      * @retval State of bit (1 or 0)
      */
    inline bool spiIsEnabledIOLock()
    {
      return ((READ_BIT(spix_->CR1, SPI_CR1_IOLOCK) == (SPI_CR1_IOLOCK)) ? true : false);
    }

    /**
      * @brief  Set Tx CRC Initialization Pattern
      * @rmtoll CR1          TCRCINI         spiSetTxCRCInitPattern
      * @param  SPIx SPI Instance
      * @param  TXCRCInitAll This parameter can be one of the following values:
      *         @arg @ref spiTXCRCINITALL_ZERO_PATTERN
      *         @arg @ref spiTXCRCINITALL_ONES_PATTERN
      * @retval None
      */
    inline void spiSetTxCRCInitPattern(SPITXCRCInitAll TXCRCInitAll)
    {
      MODIFY_REG(spix_->CR1, SPI_CR1_RCRCINI, TXCRCInitAll);
    }

    /**
      * @brief  Get Tx CRC Initialization Pattern
      * @rmtoll CR1          TCRCINI         spiGetTxCRCInitPattern
      * @param  SPIx SPI Instance
      * @retval Returned value can be one of the following values:
      *         @arg @ref spiTXCRCINITALL_ZERO_PATTERN
      *         @arg @ref spiTXCRCINITALL_ONES_PATTERN
      */
    inline SPITXCRCInitAll spiGetTxCRCInitPattern()
    {
      return (SPITXCRCInitAll)(READ_BIT(spix_->CR1, SPI_CR1_TCRCINI));
    }

    /**
      * @brief  Set Rx CRC Initialization Pattern
      * @rmtoll CR1          RCRCINI         spiSetRxCRCInitPattern
      * @param  SPIx SPI Instance
      * @param  RXCRCInitAll This parameter can be one of the following values:
      *         @arg @ref spiRXCRCINITALL_ZERO_PATTERN
      *         @arg @ref spiRXCRCINITALL_ONES_PATTERN
      * @retval None
      */
    inline void spiSetRxCRCInitPattern(SPIRXCRCInitAll RXCRCInitAll)
    {
      MODIFY_REG(spix_->CR1, SPI_CR1_RCRCINI, RXCRCInitAll);
    }

    /**
      * @brief  Get Rx CRC Initialization Pattern
      * @rmtoll CR1          RCRCINI         spiGetRxCRCInitPattern
      * @param  SPIx SPI Instance
      * @retval Returned value can be one of the following values:
      *         @arg @ref spiRXCRCINITALL_ZERO_PATTERN
      *         @arg @ref spiRXCRCINITALL_ONES_PATTERN
      */
    inline SPIRXCRCInitAll spiGetRxCRCInitPattern()
    {
      return (SPIRXCRCInitAll)(READ_BIT(spix_->CR1, SPI_CR1_RCRCINI));
    }

    /**
      * @brief  Set internal SS input level ignoring what comes from PIN.
      * @note   This configuration has effect only with config spiNSS_SOFT
      * @rmtoll CR1          SSI           spiSetInternalSSLevel
      * @param  SPIx SPI Instance
      * @param  SSLevel This parameter can be one of the following values:
      *         @arg @ref spiSS_LEVEL_HIGH
      *         @arg @ref spiSS_LEVEL_LOW
      * @retval None
      */
    inline void spiSetInternalSSLevel(SPISSLevel SSLevel)
    {
      MODIFY_REG(spix_->CR1, SPI_CR1_SSI, SSLevel);
    }

    /**
      * @brief  Get internal SS input level
      * @rmtoll CR1          SSI           spiGetInternalSSLevel
      * @param  SPIx SPI Instance
      * @retval Returned value can be one of the following values:
      *         @arg @ref spiSS_LEVEL_HIGH
      *         @arg @ref spiSS_LEVEL_LOW
      */
    inline SPISSLevel spiGetInternalSSLevel()
    {
      return (SPISSLevel)(READ_BIT(spix_->CR1, SPI_CR1_SSI));
    }

    /**
      * @brief  Enable CRC computation on 33/17 bits
      * @rmtoll CR1          CRC33_17      spiEnableFullSizeCRC
      * @param  SPIx SPI Instance
      * @retval None
      */
    inline void spiEnableFullSizeCRC()
    {
      SET_BIT(spix_->CR1, SPI_CR1_CRC33_17);
    }

    /**
      * @brief  Disable CRC computation on 33/17 bits
      * @rmtoll CR1          CRC33_17      spiDisableFullSizeCRC
      * @param  SPIx SPI Instance
      * @retval None
      */
    inline void spiDisableFullSizeCRC()
    {
      CLEAR_BIT(spix_->CR1, SPI_CR1_CRC33_17);
    }

    /**
      * @brief  Check if Enable CRC computation on 33/17 bits is enabled
      * @rmtoll CR1          CRC33_17      spiIsEnabledFullSizeCRC
      * @param  SPIx SPI Instance
      * @retval State of bit (1 or 0)
      */
    inline bool spiIsEnabledFullSizeCRC()
    {
      return ((READ_BIT(spix_->CR1, SPI_CR1_CRC33_17) == (SPI_CR1_CRC33_17)) ? true : false);
    }

    /**
      * @brief  Suspend an ongoing transfer for Master configuration
      * @rmtoll CR1          CSUSP         spiSuspendMasterTransfer
      * @param  SPIx SPI Instance
      * @retval None
      */
    inline void spiSuspendMasterTransfer()
    {
      SET_BIT(spix_->CR1, SPI_CR1_CSUSP);
    }

    /**
      * @brief  Start effective transfer on wire for Master configuration
      * @rmtoll CR1          CSTART        spiStartMasterTransfer
      * @param  SPIx SPI Instance
      * @retval None
      */
    inline void spiStartMasterTransfer()
    {
      SET_BIT(spix_->CR1, SPI_CR1_CSTART);
    }

    /**
      * @brief  Check if there is an unfinished master transfer
      * @rmtoll CR1          CSTART        spiIsActiveMasterTransfer
      * @param  SPIx SPI Instance
      * @retval State of bit (1 or 0)
      */
    inline bool spiIsActiveMasterTransfer()
    {
      return ((READ_BIT(spix_->CR1, SPI_CR1_CSTART) == (SPI_CR1_CSTART)) ? true : false);
    }

    /**
      * @brief  Enable Master Rx auto suspend in case of overrun
      * @rmtoll CR1          MASRX         spiEnableMasterRxAutoSuspend
      * @param  SPIx SPI Instance
      * @retval None
      */
    inline void spiEnableMasterRxAutoSuspend()
    {
      SET_BIT(spix_->CR1, SPI_CR1_MASRX);
    }

    /**
      * @brief  Disable Master Rx auto suspend in case of overrun
      * @rmtoll CR1          MASRX         spiDisableMasterRxAutoSuspend
      * @param  SPIx SPI Instance
      * @retval None
      */
    inline void spiDisableMasterRxAutoSuspend()
    {
      CLEAR_BIT(spix_->CR1, SPI_CR1_MASRX);
    }

    /**
      * @brief  Check if Master Rx auto suspend is activated
      * @rmtoll CR1          MASRX         spiIsEnabledMasterRxAutoSuspend
      * @param  SPIx SPI Instance
      * @retval State of bit (1 or 0)
      */
    inline bool spiIsEnabledMasterRxAutoSuspend()
    {
      return ((READ_BIT(spix_->CR1, SPI_CR1_MASRX) == (SPI_CR1_MASRX)) ? true : false);
    }

    /**
      * @brief  Set Underrun behavior
      * @note   This configuration can not be changed when SPI is enabled.
      * @rmtoll CFG1         UDRCFG        spiSetUDRConfiguration
      * @param  SPIx SPI Instance
      * @param  UDRConfig This parameter can be one of the following values:
      *         @arg @ref spiUDR_CONFIG_REGISTER_PATTERN
      *         @arg @ref spiUDR_CONFIG_LAST_RECEIVED
      *         @arg @ref spiUDR_CONFIG_LAST_TRANSMITTED
      * @retval None
      */
    inline void spiSetUDRConfiguration(SPIUDRConfig UDRConfig)
    {
      MODIFY_REG(spix_->CFG1, SPI_CFG1_UDRCFG, UDRConfig);
    }

    /**
      * @brief  Get Underrun behavior
      * @rmtoll CFG1         UDRCFG        spiGetUDRConfiguration
      * @param  SPIx SPI Instance
      * @retval Returned value can be one of the following values:
      *         @arg @ref spiUDR_CONFIG_REGISTER_PATTERN
      *         @arg @ref spiUDR_CONFIG_LAST_RECEIVED
      *         @arg @ref spiUDR_CONFIG_LAST_TRANSMITTED
      */
    inline SPIUDRConfig spiGetUDRConfiguration()
    {
      return (SPIUDRConfig)(READ_BIT(spix_->CFG1, SPI_CFG1_UDRCFG));
    }

    /**
      * @brief  Set Underrun Detection method
      * @note   This configuration can not be changed when SPI is enabled.
      * @rmtoll CFG1         UDRDET        spiSetUDRDetection
      * @param  SPIx SPI Instance
      * @param  UDRDetection This parameter can be one of the following values:
      *         @arg @ref spiUDR_DETECT_BEGIN_DATA_FRAME
      *         @arg @ref spiUDR_DETECT_END_DATA_FRAME
      *         @arg @ref spiUDR_DETECT_BEGIN_ACTIVE_NSS
      * @retval None
      */
    inline void spiSetUDRDetection(SPIUDRDetect UDRDetection)
    {
      MODIFY_REG(spix_->CFG1, SPI_CFG1_UDRDET, UDRDetection);
    }

    /**
      * @brief  Get Underrun Detection method
      * @rmtoll CFG1         UDRDET        spiGetUDRDetection
      * @param  SPIx SPI Instance
      * @retval Returned value can be one of the following values:
      *         @arg @ref spiUDR_DETECT_BEGIN_DATA_FRAME
      *         @arg @ref spiUDR_DETECT_END_DATA_FRAME
      *         @arg @ref spiUDR_DETECT_BEGIN_ACTIVE_NSS
      */
    inline SPIUDRDetect spiGetUDRDetection()
    {
      return (SPIUDRDetect)(READ_BIT(spix_->CFG1, SPI_CFG1_UDRDET));
    }

    /**
      * @brief  Set Serial protocol used
      * @note   This configuration can not be changed when SPI is enabled.
      * @rmtoll CFG2         SP            spiSetStandard
      * @param  SPIx SPI Instance
      * @param  Standard This parameter can be one of the following values:
      *         @arg @ref spiPROTOCOL_MOTOROLA
      *         @arg @ref spiPROTOCOL_TI
      * @retval None
      */
    inline void spiSetStandard(SPIProtocol Standard)
    {
      MODIFY_REG(spix_->CFG2, SPI_CFG2_SP, Standard);
    }

    /**
      * @brief  Get Serial protocol used
      * @rmtoll CFG2         SP            spiGetStandard
      * @param  SPIx SPI Instance
      * @retval Returned value can be one of the following values:
      *         @arg @ref spiPROTOCOL_MOTOROLA
      *         @arg @ref spiPROTOCOL_TI
      */
    inline SPIProtocol spiGetStandard()
    {
      return (SPIProtocol)(READ_BIT(spix_->CFG2, SPI_CFG2_SP));
    }

    /**
      * @brief  Set Clock phase
      * @note   This configuration can not be changed when SPI is enabled.
      *         This bit is not used in SPI TI mode.
      * @rmtoll CFG2         CPHA          spiSetClockPhase
      * @param  SPIx SPI Instance
      * @param  ClockPhase This parameter can be one of the following values:
      *         @arg @ref spiPHASE_1EDGE
      *         @arg @ref spiPHASE_2EDGE
      * @retval None
      */
    inline void spiSetClockPhase(SPIPhase ClockPhase)
    {
      MODIFY_REG(spix_->CFG2, SPI_CFG2_CPHA, ClockPhase);
    }

    /**
      * @brief  Get Clock phase
      * @rmtoll CFG2         CPHA          spiGetClockPhase
      * @param  SPIx SPI Instance
      * @retval Returned value can be one of the following values:
      *         @arg @ref spiPHASE_1EDGE
      *         @arg @ref spiPHASE_2EDGE
      */
    inline SPIPhase spiGetClockPhase()
    {
      return (SPIPhase)(READ_BIT(spix_->CFG2, SPI_CFG2_CPHA));
    }

    /**
      * @brief  Set Clock polarity
      * @note   This configuration can not be changed when SPI is enabled.
      *         This bit is not used in SPI TI mode.
      * @rmtoll CFG2         CPOL          spiSetClockPolarity
      * @param  SPIx SPI Instance
      * @param  ClockPolarity This parameter can be one of the following values:
      *         @arg @ref spiPOLARITY_LOW
      *         @arg @ref spiPOLARITY_HIGH
      * @retval None
      */
    inline void spiSetClockPolarity(SPINssPolarity ClockPolarity)
    {
      MODIFY_REG(spix_->CFG2, SPI_CFG2_CPOL, ClockPolarity);
    }

    /**
      * @brief  Get Clock polarity
      * @rmtoll CFG2         CPOL          spiGetClockPolarity
      * @param  SPIx SPI Instance
      * @retval Returned value can be one of the following values:
      *         @arg @ref spiPOLARITY_LOW
      *         @arg @ref spiPOLARITY_HIGH
      */
    inline SPINssPolarity spiGetClockPolarity()
    {
      return (SPINssPolarity)(READ_BIT(spix_->CFG2, SPI_CFG2_CPOL));
    }

    /**
      * @brief  Set NSS polarity
      * @note   This configuration can not be changed when SPI is enabled.
      *         This bit is not used in SPI TI mode.
      * @rmtoll CFG2         SSIOP          spiSetNSSPolarity
      * @param  SPIx SPI Instance
      * @param  NSSPolarity This parameter can be one of the following values:
      *         @arg @ref spiNSS_POLARITY_LOW
      *         @arg @ref spiNSS_POLARITY_HIGH
      * @retval None
      */
    inline void spiSetNSSPolarity(SPINssPolarity NSSPolarity)
    {
      MODIFY_REG(spix_->CFG2, SPI_CFG2_SSIOP, NSSPolarity);
    }

    /**
      * @brief  Get NSS polarity
      * @rmtoll CFG2         SSIOP          spiGetNSSPolarity
      * @param  SPIx SPI Instance
      * @retval Returned value can be one of the following values:
      *         @arg @ref spiNSS_POLARITY_LOW
      *         @arg @ref spiNSS_POLARITY_HIGH
      */
    inline SPINssPolarity spiGetNSSPolarity()
    {
      return (SPINssPolarity)(READ_BIT(spix_->CFG2, SPI_CFG2_SSIOP));
    }

    /**
      * @brief  Set Baudrate Prescaler
      * @note   This configuration can not be changed when SPI is enabled.
      *         SPI BaudRate = fPCLK/Pescaler.
      * @rmtoll CFG1         MBR           spiSetBaudRatePrescaler
      * @param  SPIx SPI Instance
      * @param  Baudrate This parameter can be one of the following values:
      *         @arg @ref spiBAUDRATEPRESCALER_DIV2
      *         @arg @ref spiBAUDRATEPRESCALER_DIV4
      *         @arg @ref spiBAUDRATEPRESCALER_DIV8
      *         @arg @ref spiBAUDRATEPRESCALER_DIV16
      *         @arg @ref spiBAUDRATEPRESCALER_DIV32
      *         @arg @ref spiBAUDRATEPRESCALER_DIV64
      *         @arg @ref spiBAUDRATEPRESCALER_DIV128
      *         @arg @ref spiBAUDRATEPRESCALER_DIV256
      * @retval None
      */
    inline void spiSetBaudRatePrescaler(SPIBaudRatePrescaler Baudrate)
    {
      MODIFY_REG(spix_->CFG1, SPI_CFG1_MBR, Baudrate);
    }

    /**
      * @brief  Get Baudrate Prescaler
      * @rmtoll CFG1         MBR           spiGetBaudRatePrescaler
      * @param  SPIx SPI Instance
      * @retval Returned value can be one of the following values:
      *         @arg @ref spiBAUDRATEPRESCALER_DIV2
      *         @arg @ref spiBAUDRATEPRESCALER_DIV4
      *         @arg @ref spiBAUDRATEPRESCALER_DIV8
      *         @arg @ref spiBAUDRATEPRESCALER_DIV16
      *         @arg @ref spiBAUDRATEPRESCALER_DIV32
      *         @arg @ref spiBAUDRATEPRESCALER_DIV64
      *         @arg @ref spiBAUDRATEPRESCALER_DIV128
      *         @arg @ref spiBAUDRATEPRESCALER_DIV256
      */
    inline SPIBaudRatePrescaler spiGetBaudRatePrescaler()
    {
      return (SPIBaudRatePrescaler)(READ_BIT(spix_->CFG1, SPI_CFG1_MBR));
    }

    /**
      * @brief  Set Transfer Bit Order
      * @note   This configuration can not be changed when SPI is enabled.
      *         This bit is not used in SPI TI mode.
      * @rmtoll CFG2         LSBFRST       spiSetTransferBitOrder
      * @param  SPIx SPI Instance
      * @param  BitOrder This parameter can be one of the following values:
      *         @arg @ref spiLSB_FIRST
      *         @arg @ref spiMSB_FIRST
      * @retval None
      */
    inline void spiSetTransferBitOrder(SPIBitOrder BitOrder)
    {
      MODIFY_REG(spix_->CFG2, SPI_CFG2_LSBFRST, BitOrder);
    }

    /**
      * @brief  Get Transfer Bit Order
      * @rmtoll CFG2         LSBFRST       spiGetTransferBitOrder
      * @param  SPIx SPI Instance
      * @retval Returned value can be one of the following values:
      *         @arg @ref spiLSB_FIRST
      *         @arg @ref spiMSB_FIRST
      */
    inline SPIBitOrder spiGetTransferBitOrder()
    {
      return (SPIBitOrder)(READ_BIT(spix_->CFG2, SPI_CFG2_LSBFRST));
    }

    /**
      * @brief  Set Transfer Mode
      * @note   This configuration can not be changed when SPI is enabled except for half duplex direction
      *         using spiSetHalfDuplexDirection.
      * @rmtoll CR1          HDDIR         spiSetTransferDirection\n
      *         CFG2         COMM          spiSetTransferDirection
      * @param  SPIx SPI Instance
      * @param  TransferDirection This parameter can be one of the following values:
      *         @arg @ref spiFULL_DUPLEX
      *         @arg @ref spiSIMPLEX_TX
      *         @arg @ref spiSIMPLEX_RX
      *         @arg @ref spiHALF_DUPLEX_RX
      *         @arg @ref spiHALF_DUPLEX_TX
      * @retval None
      */
    inline void spiSetTransferDirection(SPITransferMode TransferDirection)
    {
      MODIFY_REG(spix_->CR1, SPI_CR1_HDDIR,  TransferDirection & SPI_CR1_HDDIR);
      MODIFY_REG(spix_->CFG2, SPI_CFG2_COMM, TransferDirection & SPI_CFG2_COMM);
    }

    /**
      * @brief  Get Transfer Mode
      * @rmtoll CR1          HDDIR         spiGetTransferDirection\n
      *         CFG2         COMM          spiGetTransferDirection
      * @param  SPIx SPI Instance
      * @retval Returned value can be one of the following values:
      *         @arg @ref spiFULL_DUPLEX
      *         @arg @ref spiSIMPLEX_TX
      *         @arg @ref spiSIMPLEX_RX
      *         @arg @ref spiHALF_DUPLEX_RX
      *         @arg @ref spiHALF_DUPLEX_TX
      */
    inline SPITransferMode spiGetTransferDirection()
    {
      uint32_t Hddir = READ_BIT(spix_->CR1, SPI_CR1_HDDIR);
      uint32_t Comm = READ_BIT(spix_->CFG2, SPI_CFG2_COMM);
      return (SPITransferMode)(Hddir | Comm);
    }

    /**
      * @brief  Set direction for Half-Duplex Mode
      * @note   In master mode the MOSI pin is used and in slave mode the MISO pin is used for Half-Duplex.
      * @rmtoll CR1          HDDIR         spiSetHalfDuplexDirection
      * @param  SPIx SPI Instance
      * @param  HalfDuplexDirection This parameter can be one of the following values:
      *         @arg @ref spiHALF_DUPLEX_RX
      *         @arg @ref spiHALF_DUPLEX_TX
      * @retval None
      */
    inline void spiSetHalfDuplexDirection(SPITransferMode HalfDuplexDirection)
    {
      MODIFY_REG(spix_->CR1, SPI_CR1_HDDIR, HalfDuplexDirection & SPI_CR1_HDDIR);
    }

    /**
      * @brief  Get direction for Half-Duplex Mode
      * @note   In master mode the MOSI pin is used and in slave mode the MISO pin is used for Half-Duplex.
      * @rmtoll CR1          HDDIR         spiGetHalfDuplexDirection
      * @param  SPIx SPI Instance
      * @retval Returned value can be one of the following values:
      *         @arg @ref spiHALF_DUPLEX_RX
      *         @arg @ref spiHALF_DUPLEX_TX
      */
    inline SPITransferMode spiGetHalfDuplexDirection()
    {
      return (SPITransferMode)(READ_BIT(spix_->CR1, SPI_CR1_HDDIR) | SPI_CFG2_COMM);
    }

    /**
      * @brief  Set Frame Data Size
      * @note   This configuration can not be changed when SPI is enabled.
      * @rmtoll CFG1         DSIZE         spiSetDataWidth
      * @param  SPIx SPI Instance
      * @param  DataWidth This parameter can be one of the following values:
      *         @arg @ref spiDATAWIDTH_4BIT
      *         @arg @ref spiDATAWIDTH_5BIT
      *         @arg @ref spiDATAWIDTH_6BIT
      *         @arg @ref spiDATAWIDTH_7BIT
      *         @arg @ref spiDATAWIDTH_8BIT
      *         @arg @ref spiDATAWIDTH_9BIT
      *         @arg @ref spiDATAWIDTH_10BIT
      *         @arg @ref spiDATAWIDTH_11BIT
      *         @arg @ref spiDATAWIDTH_12BIT
      *         @arg @ref spiDATAWIDTH_13BIT
      *         @arg @ref spiDATAWIDTH_14BIT
      *         @arg @ref spiDATAWIDTH_15BIT
      *         @arg @ref spiDATAWIDTH_16BIT
      *         @arg @ref spiDATAWIDTH_17BIT
      *         @arg @ref spiDATAWIDTH_18BIT
      *         @arg @ref spiDATAWIDTH_19BIT
      *         @arg @ref spiDATAWIDTH_20BIT
      *         @arg @ref spiDATAWIDTH_21BIT
      *         @arg @ref spiDATAWIDTH_22BIT
      *         @arg @ref spiDATAWIDTH_23BIT
      *         @arg @ref spiDATAWIDTH_24BIT
      *         @arg @ref spiDATAWIDTH_25BIT
      *         @arg @ref spiDATAWIDTH_26BIT
      *         @arg @ref spiDATAWIDTH_27BIT
      *         @arg @ref spiDATAWIDTH_28BIT
      *         @arg @ref spiDATAWIDTH_29BIT
      *         @arg @ref spiDATAWIDTH_30BIT
      *         @arg @ref spiDATAWIDTH_31BIT
      *         @arg @ref spiDATAWIDTH_32BIT
      * @retval None
      */
    inline void spiSetDataWidth(SPIDataWidth DataWidth)
    {
      MODIFY_REG(spix_->CFG1, SPI_CFG1_DSIZE, DataWidth);
    }

    /**
      * @brief  Get Frame Data Size
      * @rmtoll CFG1         DSIZE         spiGetDataWidth
      * @param  SPIx SPI Instance
      * @retval Returned value can be one of the following values:
      *         @arg @ref spiDATAWIDTH_4BIT
      *         @arg @ref spiDATAWIDTH_5BIT
      *         @arg @ref spiDATAWIDTH_6BIT
      *         @arg @ref spiDATAWIDTH_7BIT
      *         @arg @ref spiDATAWIDTH_8BIT
      *         @arg @ref spiDATAWIDTH_9BIT
      *         @arg @ref spiDATAWIDTH_10BIT
      *         @arg @ref spiDATAWIDTH_11BIT
      *         @arg @ref spiDATAWIDTH_12BIT
      *         @arg @ref spiDATAWIDTH_13BIT
      *         @arg @ref spiDATAWIDTH_14BIT
      *         @arg @ref spiDATAWIDTH_15BIT
      *         @arg @ref spiDATAWIDTH_16BIT
      *         @arg @ref spiDATAWIDTH_17BIT
      *         @arg @ref spiDATAWIDTH_18BIT
      *         @arg @ref spiDATAWIDTH_19BIT
      *         @arg @ref spiDATAWIDTH_20BIT
      *         @arg @ref spiDATAWIDTH_21BIT
      *         @arg @ref spiDATAWIDTH_22BIT
      *         @arg @ref spiDATAWIDTH_23BIT
      *         @arg @ref spiDATAWIDTH_24BIT
      *         @arg @ref spiDATAWIDTH_25BIT
      *         @arg @ref spiDATAWIDTH_26BIT
      *         @arg @ref spiDATAWIDTH_27BIT
      *         @arg @ref spiDATAWIDTH_28BIT
      *         @arg @ref spiDATAWIDTH_29BIT
      *         @arg @ref spiDATAWIDTH_30BIT
      *         @arg @ref spiDATAWIDTH_31BIT
      *         @arg @ref spiDATAWIDTH_32BIT
      */
    inline SPIDataWidth spiGetDataWidth()
    {
      return (SPIDataWidth)(READ_BIT(spix_->CFG1, SPI_CFG1_DSIZE));
    }

    /**
      * @brief  Set threshold of FIFO that triggers a transfer event
      * @note   This configuration can not be changed when SPI is enabled.
      * @rmtoll CFG1         FTHLV         spiSetFIFOThreshold
      * @param  SPIx SPI Instance
      * @param  Threshold This parameter can be one of the following values:
      *         @arg @ref spiFIFO_TH_01DATA
      *         @arg @ref spiFIFO_TH_02DATA
      *         @arg @ref spiFIFO_TH_03DATA
      *         @arg @ref spiFIFO_TH_04DATA
      *         @arg @ref spiFIFO_TH_05DATA
      *         @arg @ref spiFIFO_TH_06DATA
      *         @arg @ref spiFIFO_TH_07DATA
      *         @arg @ref spiFIFO_TH_08DATA
      *         @arg @ref spiFIFO_TH_09DATA
      *         @arg @ref spiFIFO_TH_10DATA
      *         @arg @ref spiFIFO_TH_11DATA
      *         @arg @ref spiFIFO_TH_12DATA
      *         @arg @ref spiFIFO_TH_13DATA
      *         @arg @ref spiFIFO_TH_14DATA
      *         @arg @ref spiFIFO_TH_15DATA
      *         @arg @ref spiFIFO_TH_16DATA
      * @retval None
      */
    inline void spiSetFIFOThreshold(SPIFifoThreshold Threshold)
    {
      MODIFY_REG(spix_->CFG1, SPI_CFG1_FTHLV, Threshold);
    }

    /**
      * @brief  Get threshold of FIFO that triggers a transfer event
      * @rmtoll CFG1         FTHLV         spiGetFIFOThreshold
      * @param  SPIx SPI Instance
      * @retval Returned value can be one of the following values:
      *         @arg @ref spiFIFO_TH_01DATA
      *         @arg @ref spiFIFO_TH_02DATA
      *         @arg @ref spiFIFO_TH_03DATA
      *         @arg @ref spiFIFO_TH_04DATA
      *         @arg @ref spiFIFO_TH_05DATA
      *         @arg @ref spiFIFO_TH_06DATA
      *         @arg @ref spiFIFO_TH_07DATA
      *         @arg @ref spiFIFO_TH_08DATA
      *         @arg @ref spiFIFO_TH_09DATA
      *         @arg @ref spiFIFO_TH_10DATA
      *         @arg @ref spiFIFO_TH_11DATA
      *         @arg @ref spiFIFO_TH_12DATA
      *         @arg @ref spiFIFO_TH_13DATA
      *         @arg @ref spiFIFO_TH_14DATA
      *         @arg @ref spiFIFO_TH_15DATA
      *         @arg @ref spiFIFO_TH_16DATA
      */
    inline SPIFifoThreshold spiGetFIFOThreshold()
    {
      return (SPIFifoThreshold)(READ_BIT(spix_->CFG1, SPI_CFG1_FTHLV));
    }

    /**
      * @brief  Enable CRC
      * @note   This configuration can not be changed when SPI is enabled.
      * @rmtoll CFG1         CRCEN         spiEnableCRC
      * @param  SPIx SPI Instance
      * @retval None
      */
    inline void spiEnableCRC()
    {
      SET_BIT(spix_->CFG1, SPI_CFG1_CRCEN);
    }

    /**
      * @brief  Disable CRC
      * @rmtoll CFG1         CRCEN         spiDisableCRC
      * @param  SPIx SPI Instance
      * @retval None
      */
    inline void spiDisableCRC()
    {
      CLEAR_BIT(spix_->CFG1, SPI_CFG1_CRCEN);
    }

    /**
      * @brief  Check if CRC is enabled
      * @rmtoll CFG1         CRCEN         spiIsEnabledCRC
      * @param  SPIx SPI Instance
      * @retval State of bit (1 or 0).
      */
    inline bool spiIsEnabledCRC()
    {
      return ((READ_BIT(spix_->CFG1, SPI_CFG1_CRCEN) == SPI_CFG1_CRCEN) ? true : false);
    }

    /**
      * @brief  Set CRC Length
      * @note   This configuration can not be changed when SPI is enabled.
      * @rmtoll CFG1         CRCSIZE       spiSetCRCWidth
      * @param  SPIx SPI Instance
      * @param  CRCLength This parameter can be one of the following values:
      *         @arg @ref spiCRC_4BIT
      *         @arg @ref spiCRC_5BIT
      *         @arg @ref spiCRC_6BIT
      *         @arg @ref spiCRC_7BIT
      *         @arg @ref spiCRC_8BIT
      *         @arg @ref spiCRC_9BIT
      *         @arg @ref spiCRC_10BIT
      *         @arg @ref spiCRC_11BIT
      *         @arg @ref spiCRC_12BIT
      *         @arg @ref spiCRC_13BIT
      *         @arg @ref spiCRC_14BIT
      *         @arg @ref spiCRC_15BIT
      *         @arg @ref spiCRC_16BIT
      *         @arg @ref spiCRC_17BIT
      *         @arg @ref spiCRC_18BIT
      *         @arg @ref spiCRC_19BIT
      *         @arg @ref spiCRC_20BIT
      *         @arg @ref spiCRC_21BIT
      *         @arg @ref spiCRC_22BIT
      *         @arg @ref spiCRC_23BIT
      *         @arg @ref spiCRC_24BIT
      *         @arg @ref spiCRC_25BIT
      *         @arg @ref spiCRC_26BIT
      *         @arg @ref spiCRC_27BIT
      *         @arg @ref spiCRC_28BIT
      *         @arg @ref spiCRC_29BIT
      *         @arg @ref spiCRC_30BIT
      *         @arg @ref spiCRC_31BIT
      *         @arg @ref spiCRC_32BIT
      * @retval None
      */
    inline void spiSetCRCWidth(SPICrcLen CRCLength)
    {
      MODIFY_REG(spix_->CFG1, SPI_CFG1_CRCSIZE, CRCLength);
    }

    /**
      * @brief  Get CRC Length
      * @rmtoll CFG1          CRCSIZE       spiGetCRCWidth
      * @param  SPIx SPI Instance
      * @retval Returned value can be one of the following values:
      *         @arg @ref spiCRC_4BIT
      *         @arg @ref spiCRC_5BIT
      *         @arg @ref spiCRC_6BIT
      *         @arg @ref spiCRC_7BIT
      *         @arg @ref spiCRC_8BIT
      *         @arg @ref spiCRC_9BIT
      *         @arg @ref spiCRC_10BIT
      *         @arg @ref spiCRC_11BIT
      *         @arg @ref spiCRC_12BIT
      *         @arg @ref spiCRC_13BIT
      *         @arg @ref spiCRC_14BIT
      *         @arg @ref spiCRC_15BIT
      *         @arg @ref spiCRC_16BIT
      *         @arg @ref spiCRC_17BIT
      *         @arg @ref spiCRC_18BIT
      *         @arg @ref spiCRC_19BIT
      *         @arg @ref spiCRC_20BIT
      *         @arg @ref spiCRC_21BIT
      *         @arg @ref spiCRC_22BIT
      *         @arg @ref spiCRC_23BIT
      *         @arg @ref spiCRC_24BIT
      *         @arg @ref spiCRC_25BIT
      *         @arg @ref spiCRC_26BIT
      *         @arg @ref spiCRC_27BIT
      *         @arg @ref spiCRC_28BIT
      *         @arg @ref spiCRC_29BIT
      *         @arg @ref spiCRC_30BIT
      *         @arg @ref spiCRC_31BIT
      *         @arg @ref spiCRC_32BIT
      */
    inline SPICrcLen spiGetCRCWidth()
    {
      return (SPICrcLen)(READ_BIT(spix_->CFG1, SPI_CFG1_CRCSIZE));
    }

    /**
      * @brief  Set NSS Mode
      * @note   This configuration can not be changed when SPI is enabled.
      *         This bit is not used in SPI TI mode.
      * @rmtoll CFG2         SSM           spiSetNSSMode\n
      *         CFG2         SSOE          spiSetNSSMode
      * @param  SPIx SPI Instance
      * @param  NSS This parameter can be one of the following values:
      *         @arg @ref spiNSS_SOFT
      *         @arg @ref spiNSS_HARD_INPUT
      *         @arg @ref spiNSS_HARD_OUTPUT
      * @retval None
      */
    inline void spiSetNSSMode(SPINSSMode NSS)
    {
      MODIFY_REG(spix_->CFG2, SPI_CFG2_SSM | SPI_CFG2_SSOE, NSS);
    }

    /**
      * @brief  Set NSS Mode
      * @rmtoll CFG2         SSM           spiGetNSSMode\n
      *         CFG2         SSOE          spiGetNSSMode
      * @param  SPIx SPI Instance
      * @retval Returned value can be one of the following values:
      *         @arg @ref spiNSS_SOFT
      *         @arg @ref spiNSS_HARD_INPUT
      *         @arg @ref spiNSS_HARD_OUTPUT
      */
    inline SPINSSMode spiGetNSSMode()
    {
      return (SPINSSMode)(READ_BIT(spix_->CFG2, SPI_CFG2_SSM | SPI_CFG2_SSOE));
    }

    /**
      * @brief  Enable NSS pulse mgt
      * @note   This configuration can not be changed when SPI is enabled.
      *         This bit is not used in SPI TI mode.
      * @rmtoll CFG2         SSOM          spiEnableNSSPulseMgt
      * @param  SPIx SPI Instance
      * @retval None
      */
    inline void spiEnableNSSPulseMgt()
    {
      SET_BIT(spix_->CFG2, SPI_CFG2_SSOM);
    }

    /**
      * @brief  Disable NSS pulse mgt
      * @note   This configuration can not be changed when SPI is enabled.
      *         This bit is not used in SPI TI mode.
      * @rmtoll CFG2         SSOM          spiDisableNSSPulseMgt
      * @param  SPIx SPI Instance
      * @retval None
      */
    inline void spiDisableNSSPulseMgt()
    {
      CLEAR_BIT(spix_->CFG2, SPI_CFG2_SSOM);
    }

    /**
      * @brief  Check if NSS pulse is enabled
      * @rmtoll CFG2         SSOM          spiIsEnabledNSSPulse
      * @param  SPIx SPI Instance
      * @retval State of bit (1 or 0)
      */
    inline bool spiIsEnabledNSSPulse()
    {
      return ((READ_BIT(spix_->CFG2, SPI_CFG2_SSOM) == SPI_CFG2_SSOM) ? true : false);
    }

    /**
      * @}
      */

    /** @defgroup SPI_LL_EF_FlagManagement FlagManagement
      * @{
      */

    /**
      * @brief  Check if there is enough data in FIFO to read a full packet
      * @rmtoll SR           RXP           spiIsActiveFlagRXP
      * @param  SPIx SPI Instance
      * @retval State of bit (1 or 0)
      */
    inline bool spiIsActiveFlagRXP()
    {
      return ((READ_BIT(spix_->SR, SPI_SR_RXP) == (SPI_SR_RXP)) ? true : false);
    }

    /**
      * @brief  Check if there is enough space in FIFO to hold a full packet
      * @rmtoll SR           TXP           spiIsActiveFlagTXP
      * @param  SPIx SPI Instance
      * @retval State of bit (1 or 0)
      */
    inline bool spiIsActiveFlagTXP()
    {
      return ((READ_BIT(spix_->SR, SPI_SR_TXP) == (SPI_SR_TXP)) ? true : false);
    }

    /**
      * @brief  Check if there enough space in FIFO to hold a full packet, AND enough data to read a full packet
      * @rmtoll SR           DXP           spiIsActiveFlagDXP
      * @param  SPIx SPI Instance
      * @retval State of bit (1 or 0)
      */
    inline bool spiIsActiveFlagDXP()
    {
      return ((READ_BIT(spix_->SR, SPI_SR_DXP) == (SPI_SR_DXP)) ? true : false);
    }

    /**
      * @brief  Check that end of transfer event occurred
      * @rmtoll SR           EOT           spiIsActiveFlagEOT
      * @param  SPIx SPI Instance
      * @retval State of bit (1 or 0).
      */
    inline bool spiIsActiveFlagEOT()
    {
      return ((READ_BIT(spix_->SR, SPI_SR_EOT) == (SPI_SR_EOT)) ? true : false);
    }

    /**
      * @brief  Check that all required data has been filled in the fifo according to transfer size
      * @rmtoll SR           TXTF          spiIsActiveFlagTXTF
      * @param  SPIx SPI Instance
      * @retval State of bit (1 or 0).
      */
    inline bool spiIsActiveFlagTXTF()
    {
      return ((READ_BIT(spix_->SR, SPI_SR_TXTF) == (SPI_SR_TXTF)) ? true : false);
    }

    /**
      * @brief  Get Underrun error flag
      * @rmtoll SR           UDR           spiIsActiveFlagUDR
      * @param  SPIx SPI Instance
      * @retval State of bit (1 or 0).
      */
    inline bool spiIsActiveFlagUDR()
    {
      return ((READ_BIT(spix_->SR, SPI_SR_UDR) == (SPI_SR_UDR)) ? true : false);
    }

    /**
      * @brief  Get CRC error flag
      * @rmtoll SR           CRCE        spiIsActiveFlagCRCERR
      * @param  SPIx SPI Instance
      * @retval State of bit (1 or 0).
      */
    inline bool spiIsActiveFlagCRCERR()
    {
      return ((READ_BIT(spix_->SR, SPI_SR_CRCE) == (SPI_SR_CRCE)) ? true : false);
    }

    /**
      * @brief  Get  Mode fault error flag
      * @rmtoll SR           MODF          spiIsActiveFlagMODF
      * @param  SPIx SPI Instance
      * @retval State of bit (1 or 0).
      */
    inline bool spiIsActiveFlagMODF()
    {
      return ((READ_BIT(spix_->SR, SPI_SR_MODF) == (SPI_SR_MODF)) ? true : false);
    }

    /**
      * @brief  Get Overrun error flag
      * @rmtoll SR           OVR           spiIsActiveFlagOVR
      * @param  SPIx SPI Instance
      * @retval State of bit (1 or 0).
      */
    inline bool spiIsActiveFlagOVR()
    {
      return ((READ_BIT(spix_->SR, SPI_SR_OVR) == (SPI_SR_OVR)) ? true : false);
    }

    /**
      * @brief  Get TI Frame format error flag
      * @rmtoll SR           TIFRE         spiIsActiveFlagFRE
      * @param  SPIx SPI Instance
      * @retval State of bit (1 or 0).
      */
    inline bool spiIsActiveFlagFRE()
    {
      return ((READ_BIT(spix_->SR, SPI_SR_TIFRE) == (SPI_SR_TIFRE)) ? true : false);
    }

    /**
      * @brief  Check if the additional number of data has been reloaded
      * @rmtoll SR           TSERF         spiIsActiveFlagTSER
      * @param  SPIx SPI Instance
      * @retval State of bit (1 or 0).
      */
    inline bool spiIsActiveFlagTSER()
    {
      return ((READ_BIT(spix_->SR, SPI_SR_TSERF) == (SPI_SR_TSERF)) ? true : false);
    }

    /**
      * @brief  Check if a suspend operation is done
      * @rmtoll SR           SUSP          spiIsActiveFlagSUSP
      * @param  SPIx SPI Instance
      * @retval State of bit (1 or 0)
      */
    inline bool spiIsActiveFlagSUSP()
    {
      return ((READ_BIT(spix_->SR, SPI_SR_SUSP) == (SPI_SR_SUSP)) ? true : false);
    }

    /**
      * @brief  Check if last TxFIFO or CRC frame transmission is completed
      * @rmtoll SR           TXC           spiIsActiveFlagTXC
      * @param  SPIx SPI Instance
      * @retval State of bit (1 or 0).
      */
    inline bool spiIsActiveFlagTXC()
    {
      return ((READ_BIT(spix_->SR, SPI_SR_TXC) == (SPI_SR_TXC)) ? true : false);
    }

    /**
      * @brief  Check if at least one 32-bit data is available in RxFIFO
      * @rmtoll SR           RXWNE         spiIsActiveFlagRXWNE
      * @param  SPIx SPI Instance
      * @retval State of bit (1 or 0)
      */
    inline bool spiIsActiveFlagRXWNE()
    {
      return ((READ_BIT(spix_->SR, SPI_SR_RXWNE) == (SPI_SR_RXWNE)) ? true : false);
    }

    /**
      * @brief  Get number of data framed remaining in current TSIZE
      * @rmtoll SR           CTSIZE           spiGetRemainingDataFrames
      * @param  SPIx SPI Instance
      * @retval 0..0xFFFF
      */
    inline uint32_t spiGetRemainingDataFrames()
    {
      return (uint32_t)(READ_BIT(spix_->SR, SPI_SR_CTSIZE) >> SPI_SR_CTSIZE_Pos);
    }

    /**
      * @brief  Get RxFIFO packing Level
      * @rmtoll SR           RXPLVL        spiGetRxFIFOPackingLevel
      * @param  SPIx SPI Instance
      * @retval Returned value can be one of the following values:
      *         @arg @ref spiRX_FIFO_0PACKET
      *         @arg @ref spiRX_FIFO_1PACKET
      *         @arg @ref spiRX_FIFO_2PACKET
      *         @arg @ref spiRX_FIFO_3PACKET
      */
    inline uint32_t spiGetRxFIFOPackingLevel()
    {
      return (uint32_t)(READ_BIT(spix_->SR, SPI_SR_RXPLVL));
    }

    /**
      * @brief  Clear End Of Transfer flag
      * @rmtoll IFCR         EOTC          spiClearFlagEOT
      * @param  SPIx SPI Instance
      * @retval None
      */
    inline void spiClearFlagEOT()
    {
      SET_BIT(spix_->IFCR, SPI_IFCR_EOTC);
    }

    /**
      * @brief  Clear TXTF flag
      * @rmtoll IFCR         TXTFC         spiClearFlagTXTF
      * @param  SPIx SPI Instance
      * @retval None
      */
    inline void spiClearFlagTXTF()
    {
      SET_BIT(spix_->IFCR, SPI_IFCR_TXTFC);
    }

    /**
      * @brief  Clear Underrun error flag
      * @rmtoll IFCR         UDRC          spiClearFlagUDR
      * @param  SPIx SPI Instance
      * @retval None
      */
    inline void spiClearFlagUDR()
    {
      SET_BIT(spix_->IFCR, SPI_IFCR_UDRC);
    }

    /**
      * @brief  Clear Overrun error flag
      * @rmtoll IFCR         OVRC          spiClearFlagOVR
      * @param  SPIx SPI Instance
      * @retval None
      */
    inline void spiClearFlagOVR()
    {
      SET_BIT(spix_->IFCR, SPI_IFCR_OVRC);
    }

    /**
      * @brief  Clear CRC error flag
      * @rmtoll IFCR         CRCEC        spiClearFlagCRCERR
      * @param  SPIx SPI Instance
      * @retval None
      */
    inline void spiClearFlagCRCERR()
    {
      SET_BIT(spix_->IFCR, SPI_IFCR_CRCEC);
    }

    /**
      * @brief  Clear  Mode fault error flag
      * @rmtoll IFCR         MODFC         spiClearFlagMODF
      * @param  SPIx SPI Instance
      * @retval None
      */
    inline void spiClearFlagMODF()
    {
      SET_BIT(spix_->IFCR, SPI_IFCR_MODFC);
    }

    /**
      * @brief  Clear Frame format error flag
      * @rmtoll IFCR         TIFREC        spiClearFlagFRE
      * @param  SPIx SPI Instance
      * @retval None
      */
    inline void spiClearFlagFRE()
    {
      SET_BIT(spix_->IFCR, SPI_IFCR_TIFREC);
    }

    /**
      * @brief  Clear TSER flag
      * @rmtoll IFCR         TSERFC        spiClearFlagTSER
      * @param  SPIx SPI Instance
      * @retval None
      */
    inline void spiClearFlagTSER()
    {
      SET_BIT(spix_->IFCR, SPI_IFCR_TSERFC);
    }

    /**
      * @brief  Clear SUSP flag
      * @rmtoll IFCR         SUSPC         spiClearFlagSUSP
      * @param  SPIx SPI Instance
      * @retval None
      */
    inline void spiClearFlagSUSP()
    {
      SET_BIT(spix_->IFCR, SPI_IFCR_SUSPC);
    }

    /**
      * @}
      */

    /** @defgroup SPI_LL_EF_ITManagement ITManagement
      * @{
      */

    /**
      * @brief  Enable Rx Packet available IT
      * @rmtoll IER          RXPIE         spiEnableITRXP
      * @param  SPIx SPI Instance
      * @retval None
      */
    inline void spiEnableITRXP()
    {
      SET_BIT(spix_->IER, SPI_IER_RXPIE);
    }

    /**
      * @brief  Enable Tx Packet space available IT
      * @rmtoll IER          TXPIE         spiEnableITTXP
      * @param  SPIx SPI Instance
      * @retval None
      */
    inline void spiEnableITTXP()
    {
      SET_BIT(spix_->IER, SPI_IER_TXPIE);
    }

    /**
      * @brief  Enable Duplex Packet available IT
      * @rmtoll IER          DXPIE         spiEnableITDXP
      * @param  SPIx SPI Instance
      * @retval None
      */
    inline void spiEnableITDXP()
    {
      SET_BIT(spix_->IER, SPI_IER_DXPIE);
    }

    /**
      * @brief  Enable End Of Transfer IT
      * @rmtoll IER          EOTIE         spiEnableITEOT
      * @param  SPIx SPI Instance
      * @retval None
      */
    inline void spiEnableITEOT()
    {
      SET_BIT(spix_->IER, SPI_IER_EOTIE);
    }

    /**
      * @brief  Enable TXTF IT
      * @rmtoll IER          TXTFIE        spiEnableITTXTF
      * @param  SPIx SPI Instance
      * @retval None
      */
    inline void spiEnableITTXTF()
    {
      SET_BIT(spix_->IER, SPI_IER_TXTFIE);
    }

    /**
      * @brief  Enable Underrun IT
      * @rmtoll IER          UDRIE         spiEnableITUDR
      * @param  SPIx SPI Instance
      * @retval None
      */
    inline void spiEnableITUDR()
    {
      SET_BIT(spix_->IER, SPI_IER_UDRIE);
    }

    /**
      * @brief  Enable Overrun IT
      * @rmtoll IER          OVRIE         spiEnableITOVR
      * @param  SPIx SPI Instance
      * @retval None
      */
    inline void spiEnableITOVR()
    {
      SET_BIT(spix_->IER, SPI_IER_OVRIE);
    }

    /**
      * @brief  Enable CRC Error IT
      * @rmtoll IER          CRCEIE        spiEnableITCRCERR
      * @param  SPIx SPI Instance
      * @retval None
      */
    inline void spiEnableITCRCERR()
    {
      SET_BIT(spix_->IER, SPI_IER_CRCEIE);
    }

    /**
      * @brief  Enable TI Frame Format Error IT
      * @rmtoll IER          TIFREIE       spiEnableITFRE
      * @param  SPIx SPI Instance
      * @retval None
      */
    inline void spiEnableITFRE()
    {
      SET_BIT(spix_->IER, SPI_IER_TIFREIE);
    }

    /**
      * @brief  Enable MODF IT
      * @rmtoll IER          MODFIE        spiEnableITMODF
      * @param  SPIx SPI Instance
      * @retval None
      */
    inline void spiEnableITMODF()
    {
      SET_BIT(spix_->IER, SPI_IER_MODFIE);
    }

    /**
      * @brief  Enable TSER reload IT
      * @rmtoll IER          TSERFIE       spiEnableITTSER
      * @param  SPIx SPI Instance
      * @retval None
      */
    inline void spiEnableITTSER()
    {
      SET_BIT(spix_->IER, SPI_IER_TSERFIE);
    }

    /**
      * @brief  Disable Rx Packet available IT
      * @rmtoll IER          RXPIE         spiDisableITRXP
      * @param  SPIx SPI Instance
      * @retval None
      */
    inline void spiDisableITRXP()
    {
      CLEAR_BIT(spix_->IER, SPI_IER_RXPIE);
    }

    /**
      * @brief  Disable Tx Packet space available IT
      * @rmtoll IER          TXPIE         spiDisableITTXP
      * @param  SPIx SPI Instance
      * @retval None
      */
    inline void spiDisableITTXP()
    {
      CLEAR_BIT(spix_->IER, SPI_IER_TXPIE);
    }

    /**
      * @brief  Disable Duplex Packet available IT
      * @rmtoll IER          DXPIE         spiDisableITDXP
      * @param  SPIx SPI Instance
      * @retval None
      */
    inline void spiDisableITDXP()
    {
      CLEAR_BIT(spix_->IER, SPI_IER_DXPIE);
    }

    /**
      * @brief  Disable End Of Transfer IT
      * @rmtoll IER          EOTIE         spiDisableITEOT
      * @param  SPIx SPI Instance
      * @retval None
      */
    inline void spiDisableITEOT()
    {
      CLEAR_BIT(spix_->IER, SPI_IER_EOTIE);
    }

    /**
      * @brief  Disable TXTF IT
      * @rmtoll IER          TXTFIE        spiDisableITTXTF
      * @param  SPIx SPI Instance
      * @retval None
      */
    inline void spiDisableITTXTF()
    {
      CLEAR_BIT(spix_->IER, SPI_IER_TXTFIE);
    }

    /**
      * @brief  Disable Underrun IT
      * @rmtoll IER          UDRIE         spiDisableITUDR
      * @param  SPIx SPI Instance
      * @retval None
      */
    inline void spiDisableITUDR()
    {
      CLEAR_BIT(spix_->IER, SPI_IER_UDRIE);
    }

    /**
      * @brief  Disable Overrun IT
      * @rmtoll IER          OVRIE         spiDisableITOVR
      * @param  SPIx SPI Instance
      * @retval None
      */
    inline void spiDisableITOVR()
    {
      CLEAR_BIT(spix_->IER, SPI_IER_OVRIE);
    }

    /**
      * @brief  Disable CRC Error IT
      * @rmtoll IER          CRCEIE        spiDisableITCRCERR
      * @param  SPIx SPI Instance
      * @retval None
      */
    inline void spiDisableITCRCERR()
    {
      CLEAR_BIT(spix_->IER, SPI_IER_CRCEIE);
    }

    /**
      * @brief  Disable TI Frame Format Error IT
      * @rmtoll IER          TIFREIE       spiDisableITFRE
      * @param  SPIx SPI Instance
      * @retval None
      */
    inline void spiDisableITFRE()
    {
      CLEAR_BIT(spix_->IER, SPI_IER_TIFREIE);
    }

    /**
      * @brief  Disable MODF IT
      * @rmtoll IER          MODFIE        spiDisableITMODF
      * @param  SPIx SPI Instance
      * @retval None
      */
    inline void spiDisableITMODF()
    {
      CLEAR_BIT(spix_->IER, SPI_IER_MODFIE);
    }

    /**
      * @brief  Disable TSER reload IT
      * @rmtoll IER          TSERFIE       spiDisableITTSER
      * @param  SPIx SPI Instance
      * @retval None
      */
    inline void spiDisableITTSER()
    {
      CLEAR_BIT(spix_->IER, SPI_IER_TSERFIE);
    }

    /**
      * @brief  Check if Rx Packet available IT is enabled
      * @rmtoll IER          RXPIE         spiIsEnabledITRXP
      * @param  SPIx SPI Instance
      * @retval State of bit (1 or 0)
      */
    inline bool spiIsEnabledITRXP()
    {
      return ((READ_BIT(spix_->IER, SPI_IER_RXPIE) == (SPI_IER_RXPIE)) ? true : false);
    }

    /**
      * @brief  Check if Tx Packet space available IT is enabled
      * @rmtoll IER          TXPIE         spiIsEnabledITTXP
      * @param  SPIx SPI Instance
      * @retval State of bit (1 or 0)
      */
    inline bool spiIsEnabledITTXP()
    {
      return ((READ_BIT(spix_->IER, SPI_IER_TXPIE) == (SPI_IER_TXPIE)) ? true : false);
    }

    /**
      * @brief  Check if Duplex Packet available IT is enabled
      * @rmtoll IER          DXPIE         spiIsEnabledITDXP
      * @param  SPIx SPI Instance
      * @retval State of bit (1 or 0)
      */
    inline bool spiIsEnabledITDXP()
    {
      return ((READ_BIT(spix_->IER, SPI_IER_DXPIE) == (SPI_IER_DXPIE)) ? true : false);
    }

    /**
      * @brief  Check if End Of Transfer IT is enabled
      * @rmtoll IER          EOTIE         spiIsEnabledITEOT
      * @param  SPIx SPI Instance
      * @retval State of bit (1 or 0)
      */
    inline bool spiIsEnabledITEOT()
    {
      return ((READ_BIT(spix_->IER, SPI_IER_EOTIE) == (SPI_IER_EOTIE)) ? true : false);
    }

    /**
      * @brief  Check if TXTF IT is enabled
      * @rmtoll IER          TXTFIE        spiIsEnabledITTXTF
      * @param  SPIx SPI Instance
      * @retval State of bit (1 or 0)
      */
    inline bool spiIsEnabledITTXTF()
    {
      return ((READ_BIT(spix_->IER, SPI_IER_TXTFIE) == (SPI_IER_TXTFIE)) ? true : false);
    }

    /**
      * @brief  Check if Underrun IT is enabled
      * @rmtoll IER          UDRIE         spiIsEnabledITUDR
      * @param  SPIx SPI Instance
      * @retval State of bit (1 or 0)
      */
    inline bool spiIsEnabledITUDR()
    {
      return ((READ_BIT(spix_->IER, SPI_IER_UDRIE) == (SPI_IER_UDRIE)) ? true : false);
    }

    /**
      * @brief  Check if Overrun IT is enabled
      * @rmtoll IER          OVRIE         spiIsEnabledITOVR
      * @param  SPIx SPI Instance
      * @retval State of bit (1 or 0)
      */
    inline bool spiIsEnabledITOVR()
    {
      return ((READ_BIT(spix_->IER, SPI_IER_OVRIE) == (SPI_IER_OVRIE)) ? true : false);
    }

    /**
      * @brief  Check if CRC Error IT is enabled
      * @rmtoll IER          CRCEIE        spiIsEnabledITCRCERR
      * @param  SPIx SPI Instance
      * @retval State of bit (1 or 0)
      */
    inline bool spiIsEnabledITCRCERR()
    {
      return ((READ_BIT(spix_->IER, SPI_IER_CRCEIE) == (SPI_IER_CRCEIE)) ? true : false);
    }

    /**
      * @brief  Check if TI Frame Format Error IT is enabled
      * @rmtoll IER          TIFREIE       spiIsEnabledITFRE
      * @param  SPIx SPI Instance
      * @retval State of bit (1 or 0)
      */
    inline bool spiIsEnabledITFRE()
    {
      return ((READ_BIT(spix_->IER, SPI_IER_TIFREIE) == (SPI_IER_TIFREIE)) ? true : false);
    }

    /**
      * @brief  Check if MODF IT is enabled
      * @rmtoll IER          MODFIE        spiIsEnabledITMODF
      * @param  SPIx SPI Instance
      * @retval State of bit (1 or 0)
      */
    inline bool spiIsEnabledITMODF()
    {
      return ((READ_BIT(spix_->IER, SPI_IER_MODFIE) == (SPI_IER_MODFIE)) ? true : false);
    }

    /**
      * @brief  Check if TSER reload IT is enabled
      * @rmtoll IER          TSERFIE       spiIsEnabledITTSER
      * @param  SPIx SPI Instance
      * @retval State of bit (1 or 0)
      */
    inline bool spiIsEnabledITTSER()
    {
      return ((READ_BIT(spix_->IER, SPI_IER_TSERFIE) == (SPI_IER_TSERFIE)) ? true : false);
    }

    /**
      * @}
      */

    /** @defgroup SPI_LL_EF_DMA_Management DMA Management
      * @{
      */

    /**
      * @brief  Enable DMA Rx
      * @rmtoll CFG1         RXDMAEN       spiEnableDMAReqRX
      * @param  SPIx SPI Instance
      * @retval None
      */
    inline void spiEnableDMAReqRX()
    {
      SET_BIT(spix_->CFG1, SPI_CFG1_RXDMAEN);
    }

    /**
      * @brief  Disable DMA Rx
      * @rmtoll CFG1         RXDMAEN       spiDisableDMAReqRX
      * @param  SPIx SPI Instance
      * @retval None
      */
    inline void spiDisableDMAReqRX()
    {
      CLEAR_BIT(spix_->CFG1, SPI_CFG1_RXDMAEN);
    }

    /**
      * @brief  Check if DMA Rx is enabled
      * @rmtoll CFG1         RXDMAEN       spiIsEnabledDMAReqRX
      * @param  SPIx SPI Instance
      * @retval State of bit (1 or 0)
      */
    inline bool spiIsEnabledDMAReqRX()
    {
      return ((READ_BIT(spix_->CFG1, SPI_CFG1_RXDMAEN) == (SPI_CFG1_RXDMAEN)) ? true : false);
    }

    /**
      * @brief  Enable DMA Tx
      * @rmtoll CFG1         TXDMAEN       spiEnableDMAReqTX
      * @param  SPIx SPI Instance
      * @retval None
      */
    inline void spiEnableDMAReqTX()
    {
      SET_BIT(spix_->CFG1, SPI_CFG1_TXDMAEN);
    }

    /**
      * @brief  Disable DMA Tx
      * @rmtoll CFG1         TXDMAEN       spiDisableDMAReqTX
      * @param  SPIx SPI Instance
      * @retval None
      */
    inline void spiDisableDMAReqTX()
    {
      CLEAR_BIT(spix_->CFG1, SPI_CFG1_TXDMAEN);
    }

    /**
      * @brief  Check if DMA Tx is enabled
      * @rmtoll CFG1         TXDMAEN       spiIsEnabledDMAReqTX
      * @param  SPIx SPI Instance
      * @retval State of bit (1 or 0)
      */
    inline bool spiIsEnabledDMAReqTX()
    {
      return ((READ_BIT(spix_->CFG1, SPI_CFG1_TXDMAEN) == (SPI_CFG1_TXDMAEN)) ? true : false);
    }

    /**
      * @}
      */

    /** @defgroup SPI_LL_EF_DATA_Management DATA_Management
      * @{
      */

    /**
      * @brief  Read Data Register
      * @rmtoll RXDR         .       spiReceiveData8
      * @param  SPIx SPI Instance
      * @retval 0..0xFF
      */
    inline uint8_t spiReceiveData8()
    {
      return (*((__IO uint8_t *)&spix_->RXDR));
    }

    /**
      * @brief  Read Data Register
      * @rmtoll RXDR         .       spiReceiveData16
      * @param  SPIx SPI Instance
      * @retval 0..0xFFFF
      */
    inline uint16_t spiReceiveData16()
    {
      return (uint16_t)(spix_->RXDR);
    }

    /**
      * @brief  Read Data Register
      * @rmtoll RXDR         .       spiReceiveData32
      * @param  SPIx SPI Instance
      * @retval  0..0xFFFFFFFF
      */
    inline uint32_t spiReceiveData32()
    {
      return (*((__IO uint32_t *)&spix_->RXDR));
    }

    /**
      * @brief  Write Data Register
      * @rmtoll TXDR         .       spiTransmitData8
      * @param  SPIx SPI Instance
      * @param  TxData 0..0xFF
      * @retval None
      */
    inline void spiTransmitData8(uint8_t TxData)
    {
      *((__IO uint8_t *)&spix_->TXDR) = TxData;
    }

    /**
      * @brief  Write Data Register
      * @rmtoll TXDR         .       spiTransmitData16
      * @param  SPIx SPI Instance
      * @param  TxData 0..0xFFFF
      * @retval None
      */
    inline void spiTransmitData16(uint16_t TxData)
    {
    #if defined (__GNUC__)
      __IO uint16_t *spitxdr = ((__IO uint16_t *)&spix_->TXDR);
      *spitxdr = TxData;
    #else
      spix_->TXDR = TxData;
    #endif /* __GNUC__ */
    }

    /**
      * @brief  Write Data Register
      * @rmtoll TXDR         .       spiTransmitData32
      * @param  SPIx SPI Instance
      * @param  TxData 0..0xFFFFFFFF
      * @retval None
      */
    inline void spiTransmitData32(uint32_t TxData)
    {
      *((__IO uint32_t *)&spix_->TXDR) = TxData;
    }

    /**
      * @brief  Set polynomial for CRC calcul
      * @rmtoll CRCPOLY      CRCPOLY       spiSetCRCPolynomial
      * @param  SPIx SPI Instance
      * @param  CRCPoly 0..0xFFFFFFFF
      * @retval None
      */
    inline void spiSetCRCPolynomial(uint32_t CRCPoly)
    {
      WRITE_REG(spix_->CRCPOLY, CRCPoly);
    }

    /**
      * @brief  Get polynomial for CRC calcul
      * @rmtoll CRCPOLY      CRCPOLY       spiGetCRCPolynomial
      * @param  SPIx SPI Instance
      * @retval 0..0xFFFFFFFF
      */
    inline uint32_t spiGetCRCPolynomial()
    {
      return (uint32_t)(READ_REG(spix_->CRCPOLY));
    }

    /**
      * @brief  Set the underrun pattern
      * @rmtoll UDRDR        UDRDR         spiSetUDRPattern
      * @param  SPIx SPI Instance
      * @param  Pattern 0..0xFFFFFFFF
      * @retval None
      */
    inline void spiSetUDRPattern(uint32_t Pattern)
    {
      WRITE_REG(spix_->UDRDR, Pattern);
    }

    /**
      * @brief  Get the underrun pattern
      * @rmtoll UDRDR        UDRDR         spiGetUDRPattern
      * @param  SPIx SPI Instance
      * @retval 0..0xFFFFFFFF
      */
    inline uint32_t spiGetUDRPattern()
    {
      return (uint32_t)(READ_REG(spix_->UDRDR));
    }

    /**
      * @brief  Get Rx CRC
      * @rmtoll RXCRCR       RXCRC         spiGetRxCRC
      * @param  SPIx SPI Instance
      * @retval 0..0xFFFFFFFF
      */
    inline uint32_t spiGetRxCRC()
    {
      return (uint32_t)(READ_REG(spix_->RXCRC));
    }

    /**
      * @brief  Get Tx CRC
      * @rmtoll TXCRCR       TXCRC         spiGetTxCRC
      * @param  SPIx SPI Instance
      * @retval 0..0xFFFFFFFF
      */
    inline uint32_t spiGetTxCRC()
    {
      return (uint32_t)(READ_REG(spix_->TXCRC));
    }

    /** @defgroup SPI_LL_EF_Init Initialization and de-initialization functions
      * @{
      */

    eResult spiDeInit()
    {
      eResult status = E_RESULT_ERROR;
    #if defined(SPI1)
      if (spix_ == SPI1)
      {
        RCCControl::getInstance()->APB2GRP1ForceReset(RCC_APB2_GRP1_PERIPH_SPI1);
        RCCControl::getInstance()->APB2GRP1ReleaseReset(RCC_APB2_GRP1_PERIPH_SPI1);

        /* Update the return status */
        status = E_RESULT_OK;
      }
    #endif /* SPI1 */
    #if defined(SPI2)
      if (spix_ == SPI2)
      {
        RCCControl::getInstance()->APB1GRP1ForceReset(RCC_APB1_GRP1_PERIPH_SPI2);
        RCCControl::getInstance()->APB1GRP1ReleaseReset(RCC_APB1_GRP1_PERIPH_SPI2);

        /* Update the return status */
        status = E_RESULT_OK;
      }
    #endif /* SPI2 */
    #if defined(SPI3)
      if (spix_ == SPI3)
      {
        RCCControl::getInstance()->APB1GRP1ForceReset(RCC_APB1_GRP1_PERIPH_SPI3);
        RCCControl::getInstance()->APB1GRP1ReleaseReset(RCC_APB1_GRP1_PERIPH_SPI3);

        /* Update the return status */
        status = E_RESULT_OK;
      }
    #endif /* SPI3 */
    #if defined(SPI4)
      if (spix_ == SPI4)
      {
        RCCControl::getInstance()->APB2GRP1ForceReset(RCC_APB2_GRP1_PERIPH_SPI4);
        RCCControl::getInstance()->APB2GRP1ReleaseReset(RCC_APB2_GRP1_PERIPH_SPI4);

        /* Update the return status */
        status = E_RESULT_OK;
      }
    #endif /* SPI4 */
    #if defined(SPI5)
      if (spix_ == SPI5)
      {
        RCCControl::getInstance()->APB2GRP1ForceReset(RCC_APB2_GRP1_PERIPH_SPI5);
        RCCControl::getInstance()->APB2GRP1ReleaseReset(RCC_APB2_GRP1_PERIPH_SPI5);

        /* Update the return status */
        status = E_RESULT_OK;
      }
    #endif /* SPI5 */
    #if defined(SPI6)
      if (spix_ == SPI6)
      {
        RCCControl::getInstance()->APB4GRP1ForceReset(RCC_APB4_GRP1_PERIPH_SPI6);
        RCCControl::getInstance()->APB4GRP1ReleaseReset(RCC_APB4_GRP1_PERIPH_SPI6);

        /* Update the return status */
        status = E_RESULT_OK;
      }
    #endif /* SPI6 */

      return status;
    }
    eResult spiInit(SPIMode Mode, SPITransferMode TransferDirection, SPIDataWidth DataWidth = M_SPI_DATAWIDTH_8BIT, SPIBaudRatePrescaler BaudRate = M_SPI_BAUDRATEPRESCALER_DIV32, SPINSSMode NSS = M_SPI_NSS_SOFT, SPIBitOrder BitOrder = M_SPI_MSB_FIRST, 
                    SPIPolarity ClockPolarity = M_SPI_POLARITY_HIGH, SPIPhase ClockPhase = M_SPI_PHASE_2EDGE, SPICRCCalculation CRCCalculation = M_SPI_CRCCALCULATION_DISABLE, uint32_t CRCPoly = 0)
    {
      eResult status = E_RESULT_ERROR;
      uint32_t tmp_nss;
      uint32_t tmp_mode;
      uint32_t tmp_nss_polarity;

      /* Check the SPI instance is not enabled */
      if (!spiIsEnabled())
      {
        /*---------------------------- SPIx CFG1 Configuration ------------------------
          * Configure SPIx CFG1 with parameters:
          * - Master Baud Rate       : SPI_CFG1_MBR[2:0] bits
          * - CRC Computation Enable : SPI_CFG1_CRCEN bit
          * - Length of data frame   : SPI_CFG1_DSIZE[4:0] bits
          */
        MODIFY_REG(spix_->CFG1, SPI_CFG1_MBR | SPI_CFG1_CRCEN | SPI_CFG1_DSIZE, BaudRate  | CRCCalculation | DataWidth);

        tmp_nss  = NSS;
        tmp_mode = Mode;
        tmp_nss_polarity = spiGetNSSPolarity();

        /* Checks to setup Internal SS signal level and avoid a MODF Error */
        if ((tmp_nss == M_SPI_NSS_SOFT) && (((tmp_nss_polarity == M_SPI_NSS_POLARITY_LOW)  && \
                                              (tmp_mode == M_SPI_MODE_MASTER))              || \
                                            ((tmp_nss_polarity == M_SPI_NSS_POLARITY_HIGH) && \
                                              (tmp_mode == M_SPI_MODE_SLAVE))))
        {
          spiSetInternalSSLevel(M_SPI_SS_LEVEL_HIGH);
        }

        /*---------------------------- SPIx CFG2 Configuration ------------------------
          * Configure SPIx CFG2 with parameters:
          * - NSS management         : SPI_CFG2_SSM, SPI_CFG2_SSOE bits
          * - ClockPolarity          : SPI_CFG2_CPOL bit
          * - ClockPhase             : SPI_CFG2_CPHA bit
          * - BitOrder               : SPI_CFG2_LSBFRST bit
          * - Master/Slave Mode      : SPI_CFG2_MASTER bit
          * - SPI Mode               : SPI_CFG2_COMM[1:0] bits
          */
        MODIFY_REG(spix_->CFG2, SPI_CFG2_SSM   | SPI_CFG2_SSOE    |
                  SPI_CFG2_CPOL              | SPI_CFG2_CPHA    |
                  SPI_CFG2_LSBFRST           | SPI_CFG2_MASTER  | SPI_CFG2_COMM,
                  NSS        | ClockPolarity                    |
                  ClockPhase | BitOrder                         |
                  Mode       | (TransferDirection & SPI_CFG2_COMM));

        /*---------------------------- SPIx CR1 Configuration ------------------------
          * Configure SPIx CR1 with parameter:
          * - Half Duplex Direction  : SPI_CR1_HDDIR bit
          */
        MODIFY_REG(spix_->CR1, SPI_CR1_HDDIR, TransferDirection & SPI_CR1_HDDIR);

        /*---------------------------- SPIx CRCPOLY Configuration ----------------------
          * Configure SPIx CRCPOLY with parameter:
          * - CRCPoly                : CRCPOLY[31:0] bits
          */
        if (CRCCalculation == M_SPI_CRCCALCULATION_ENABLE)
        {
          if(CRCPoly >= 1UL)
          {
            spiSetCRCPolynomial(CRCPoly);
          }
        }

        /* Activate the SPI mode (Reset I2SMOD bit in I2SCFGR register) */
        CLEAR_BIT(spix_->I2SCFGR, SPI_I2SCFGR_I2SMOD);
        registerSPIIsrCb(spix_,[](void* param, SPIisrFlags isrFlag){
            COMMONSPI* spix = reinterpret_cast<COMMONSPI*>(param);
            if(spix && spix->spicb_)
            {
                spix->spicb_(spix, isrFlag);
            }
        },(void*)this);
        status = E_RESULT_OK;
      }

      return status;
    }
    void enableClk(bool bEnable = true)
    {
        RCCControl* rcc = RCCControl::getInstance();
        switch (reinterpret_cast<uint32_t>(spix_))
        {
            case SPI1_BASE:
              bEnable ? rcc->APB2GRP1EnableClock(RCC_APB2_GRP1_PERIPH_SPI1) :  rcc->APB2GRP1DisableClock(RCC_APB2_GRP1_PERIPH_SPI1);
              break;
            case SPI2_BASE:
              bEnable ? rcc->APB1GRP1EnableClock(RCC_APB1_GRP1_PERIPH_SPI2) : rcc->APB1GRP1DisableClock(RCC_APB1_GRP1_PERIPH_SPI2);
              break;
            case SPI3_BASE:
              bEnable ? rcc->APB1GRP1EnableClock(RCC_APB1_GRP1_PERIPH_SPI3) : rcc->APB1GRP1DisableClock(RCC_APB1_GRP1_PERIPH_SPI3);
              break;
            case SPI4_BASE:
              bEnable ? rcc->APB2GRP1EnableClock(RCC_APB2_GRP1_PERIPH_SPI4) : rcc->APB2GRP1DisableClock(RCC_APB2_GRP1_PERIPH_SPI4);
              break;
            case SPI5_BASE:
              bEnable ? rcc->APB2GRP1EnableClock(RCC_APB2_GRP1_PERIPH_SPI5) : rcc->APB2GRP1DisableClock(RCC_APB2_GRP1_PERIPH_SPI5);
              break;
            case SPI6_BASE:
              bEnable ? rcc->APB4GRP1EnableClock(RCC_APB4_GRP1_PERIPH_SPI6) : rcc->APB4GRP1DisableClock(RCC_APB4_GRP1_PERIPH_SPI6);
              break;
            default: break;
        }
    }
    void enableIsr(uint32_t PreemptPriority, uint32_t SubPriority)
    {
        if(NVIC_GetEnableIRQ(getIrqType()) == 0U)
        {
            NVIC_SetPriority(getIrqType(), NVIC_EncodePriority(NVIC_GetPriorityGrouping(), PreemptPriority, SubPriority));
            NVIC_EnableIRQ(getIrqType());
        }
    }
    void disableIsr()
    {
        NVIC_DisableIRQ(getIrqType());
    }
    void registerInterruptCb(const SPIInterruptCb& isrcb)
    {
        spicb_ = isrcb;
    }
    void unregisterInterruptCb()
    {
        if(spicb_)
        {
            spicb_ = SPIInterruptCb();
        }
    }
private:

    IRQn_Type getIrqType()
    {
        IRQn_Type type = TIM1_UP_IRQn;
        switch (reinterpret_cast<uint32_t>(spix_))
        {
            case SPI1_BASE:
              type = SPI1_IRQn;
              break;
            case SPI2_BASE:
              type = SPI2_IRQn;
              break;
            case SPI3_BASE:
              type = SPI3_IRQn;
              break;
            case SPI4_BASE:
              type = SPI4_IRQn;
              break;
            case SPI5_BASE:
              type = SPI5_IRQn;
              break;
            case SPI6_BASE:
              type = SPI6_IRQn;
              break;
            default: break;
        }
        return type;
    }

    SPI_TypeDef* spix_;
    SPIInterruptCb spicb_;
};