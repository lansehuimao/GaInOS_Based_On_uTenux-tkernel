#if !(((PDUR_SW_MAJOR_VERSION == 2) && (PDUR_SW_MINOR_VERSION == 0)) )
#error PduR: Configuration file expected BSW module version to be 2.0.*
#endif

#ifndef PDUR_CFG_H_
#define PDUR_CFG_H_

// Module support
#define PDUR_CANIF_SUPPORT STD_ON
#define PDUR_CANTP_SUPPORT STD_ON
#define PDUR_FRIF_SUPPORT STD_OFF  /* Not supported */
#define PDUR_FRTP_SUPPORT STD_OFF  /* Not supported */
#define PDUR_LINIF_SUPPORT STD_OFF
#define PDUR_LINTP_SUPPORT STD_OFF  /* Not supported */
#define PDUR_COM_SUPPORT STD_ON
#define PDUR_DCM_SUPPORT STD_OFF
#define PDUR_IPDUM_SUPPORT STD_OFF  /* Not supported */
#define PDUR_J1939TP_SUPPORT STD_OFF
#define PDUR_SOAD_SUPPORT STD_OFF  /* Not supported */

#define PDUR_DEV_ERROR_DETECT		STD_ON
#define PDUR_VERSION_INFO_API		STD_ON

// Zero cost operation mode
#define PDUR_ZERO_COST_OPERATION STD_OFF
#define PDUR_SINGLE_IF CAN_IF#define PDUR_SINGLE_TP CAN_TP// Gateway operation
#define PDUR_GATEWAY_OPERATION				STD_OFF
#define PDUR_MEMORY_SIZE					10 /* Not used */
#define PDUR_SB_TX_BUFFER_SUPPORT			STD_OFF
#define PDUR_FIFO_TX_BUFFER_SUPPORT			STD_OFF

/* The maximum numbers of Tx buffers. */
#define PDUR_MAX_TX_BUFFER_NUMBER			10 /* Not used */
#define PDUR_N_TP_ROUTES_WITH_BUFFER		"not understand by parai"
#define PDUR_N_TP_BUFFERS					"not understand by parai"

// Multicast,not understand by parai
#define PDUR_MULTICAST_TOIF_SUPPORT			STD_ON
#define PDUR_MULTICAST_FROMIF_SUPPORT		STD_ON
#define PDUR_MULTICAST_TOTP_SUPPORT			STD_ON
#define PDUR_MULTICAST_FROMTP_SUPPORT		STD_ON

// Minimum routing,not understand by parai
/* Minimum routing not supported.
#define PDUR_MINIMUM_ROUTING_UP_MODULE		COM
#define PDUR_MINIMUM_ROUTING_LO_MODULE		CAN_IF
#define PDUR_MINIMUM_ROUTING_UP_RXPDUID		((PduIdType)100)
#define PDUR_MINIMUM_ROUTING_LO_RXPDUID 	((PduIdType)255)
#define PDUR_MINIMUM_ROUTING_UP_TXPDUID 	((PduIdType)255)
#define PDUR_MINIMUM_ROUTING_LO_TXPDUID 	((PduIdType)255)
*/

#if(PDUR_ZERO_COST_OPERATION == STD_ON)
// Zero cost operation support active.
#if PDUR_CANIF_SUPPORT == STD_ON
#define PduR_CanIfRxIndication Com_RxIndication
#define PduR_CanIfTxConfirmation Com_TxConfirmation
#else
#define PduR_CanIfRxIndication(CanRxPduId,PduInfoPtr)
#define PduR_CanIfTxConfirmation(CanTxPduId)
#endif

#if PDUR_CANTP_SUPPORT == STD_ON
#define PduR_CanTpProvideRxBuffer Dcm_ProvideRxBuffer
#define PduR_CanTpRxIndication Dcm_RxIndication
#define PduR_CanTpProvideTxBuffer Dcm_ProvideTxBuffer
#define PduR_CanTpTxConfirmation Dcm_TxConfirmation
#else
#define PduR_CanTpProvideRxBuffer(id,length,PduInfoPtr)
#define PduR_CanTpRxIndication(CanTpRxPduId,Result)
#define PduR_CanTpProvideTxBuffer(CanTpTxId,PduinfoPtr,Length)
#define PduR_CanTpTxConfirmation(CanTpTxPduId,Result)
#endif

#if PDUR_LINIF_SUPPORT == STD_ON 
#define PduR_LinIfRxIndication Com_RxIndication
#define PduR_LinIfTxConfirmation Com_TxConfirmation
#define PduR_LinIfTriggerTransmit Com_TriggerTransmit
#else
#define PduR_LinIfRxIndication(LinRxPduId,PduInfoPtr)
#define PduR_LinIfTxConfirmation(LinTxPduId)
#define PduR_LinIfTriggerTransmit(LinTxPduId,PduInfoPtr)
#endif

#if PDUR_SOAD_SUPPORT == STD_ON
#define PduR_SoAdTpProvideRxBuffer Dcm_ProvideRxBuffer
#define PduR_SoAdTpRxIndication Dcm_RxIndication
#define PduR_SoAdTpProvideTxBuffer Dcm_ProvideTxBuffer
#define PduR_SoAdTpTxConfirmation Dcm_TxConfirmation
#else
#define PduR_SoAdProvideRxBuffer()
#define PduR_SoAdRxIndication()
#define PduR_SoAdProvideTxBuffer()
#define PduR_SoAdTxConfirmation()
#endif

#if PDUR_COM_SUPPORT == STD_ON
#define PduR_ComTransmit CanIf_Transmit
#else
#define PduR_ComTransmit(CanTxPduId,PduInfoPtr)	(E_OK)
#endif

#if PDUR_DCM_SUPPORT == STD_ON
#define PduR_DcmTransmit CanTp_Transmit
#else
#define PduR_DcmTransmit(CanTpTxSduId,CanTpTxInfoPtr)	(E_OK)
#endif
#endif  /* PDUR_ZERO_COST_OPERATION */

#endif /* PDUR_CFG_H_ */

