$(PROJECT_NAME)_$(CRC_MODULE_NAME)_CONFIG_FILES += $(CFG_OUTPUT_DIR)/Crc_Cfg.h
$(PROJECT_NAME)_$(CRC_MODULE_NAME)_CONFIG_FILES += $(CFG_OUTPUT_DIR)/Crc.mk

$(PROJECT_NAME)_CONFIG_FILES += $($(PROJECT_NAME)_$(CRC_MODULE_NAME)_CONFIG_FILES)