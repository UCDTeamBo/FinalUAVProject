	component simple_system is
		port (
			clk_clk                                : in    std_logic                     := 'X';             -- clk
			fpga_key_external_connection_export    : in    std_logic_vector(3 downto 0)  := (others => 'X'); -- export
			fpga_led_external_connection_export    : out   std_logic_vector(3 downto 0);                     -- export
			hps_io_hps_io_emac1_inst_TX_CLK        : out   std_logic;                                        -- hps_io_emac1_inst_TX_CLK
			hps_io_hps_io_emac1_inst_TXD0          : out   std_logic;                                        -- hps_io_emac1_inst_TXD0
			hps_io_hps_io_emac1_inst_TXD1          : out   std_logic;                                        -- hps_io_emac1_inst_TXD1
			hps_io_hps_io_emac1_inst_TXD2          : out   std_logic;                                        -- hps_io_emac1_inst_TXD2
			hps_io_hps_io_emac1_inst_TXD3          : out   std_logic;                                        -- hps_io_emac1_inst_TXD3
			hps_io_hps_io_emac1_inst_RXD0          : in    std_logic                     := 'X';             -- hps_io_emac1_inst_RXD0
			hps_io_hps_io_emac1_inst_MDIO          : inout std_logic                     := 'X';             -- hps_io_emac1_inst_MDIO
			hps_io_hps_io_emac1_inst_MDC           : out   std_logic;                                        -- hps_io_emac1_inst_MDC
			hps_io_hps_io_emac1_inst_RX_CTL        : in    std_logic                     := 'X';             -- hps_io_emac1_inst_RX_CTL
			hps_io_hps_io_emac1_inst_TX_CTL        : out   std_logic;                                        -- hps_io_emac1_inst_TX_CTL
			hps_io_hps_io_emac1_inst_RX_CLK        : in    std_logic                     := 'X';             -- hps_io_emac1_inst_RX_CLK
			hps_io_hps_io_emac1_inst_RXD1          : in    std_logic                     := 'X';             -- hps_io_emac1_inst_RXD1
			hps_io_hps_io_emac1_inst_RXD2          : in    std_logic                     := 'X';             -- hps_io_emac1_inst_RXD2
			hps_io_hps_io_emac1_inst_RXD3          : in    std_logic                     := 'X';             -- hps_io_emac1_inst_RXD3
			hps_io_hps_io_qspi_inst_IO0            : inout std_logic                     := 'X';             -- hps_io_qspi_inst_IO0
			hps_io_hps_io_qspi_inst_IO1            : inout std_logic                     := 'X';             -- hps_io_qspi_inst_IO1
			hps_io_hps_io_qspi_inst_IO2            : inout std_logic                     := 'X';             -- hps_io_qspi_inst_IO2
			hps_io_hps_io_qspi_inst_IO3            : inout std_logic                     := 'X';             -- hps_io_qspi_inst_IO3
			hps_io_hps_io_qspi_inst_SS0            : out   std_logic;                                        -- hps_io_qspi_inst_SS0
			hps_io_hps_io_qspi_inst_CLK            : out   std_logic;                                        -- hps_io_qspi_inst_CLK
			hps_io_hps_io_sdio_inst_CMD            : inout std_logic                     := 'X';             -- hps_io_sdio_inst_CMD
			hps_io_hps_io_sdio_inst_D0             : inout std_logic                     := 'X';             -- hps_io_sdio_inst_D0
			hps_io_hps_io_sdio_inst_D1             : inout std_logic                     := 'X';             -- hps_io_sdio_inst_D1
			hps_io_hps_io_sdio_inst_CLK            : out   std_logic;                                        -- hps_io_sdio_inst_CLK
			hps_io_hps_io_sdio_inst_D2             : inout std_logic                     := 'X';             -- hps_io_sdio_inst_D2
			hps_io_hps_io_sdio_inst_D3             : inout std_logic                     := 'X';             -- hps_io_sdio_inst_D3
			hps_io_hps_io_usb1_inst_D0             : inout std_logic                     := 'X';             -- hps_io_usb1_inst_D0
			hps_io_hps_io_usb1_inst_D1             : inout std_logic                     := 'X';             -- hps_io_usb1_inst_D1
			hps_io_hps_io_usb1_inst_D2             : inout std_logic                     := 'X';             -- hps_io_usb1_inst_D2
			hps_io_hps_io_usb1_inst_D3             : inout std_logic                     := 'X';             -- hps_io_usb1_inst_D3
			hps_io_hps_io_usb1_inst_D4             : inout std_logic                     := 'X';             -- hps_io_usb1_inst_D4
			hps_io_hps_io_usb1_inst_D5             : inout std_logic                     := 'X';             -- hps_io_usb1_inst_D5
			hps_io_hps_io_usb1_inst_D6             : inout std_logic                     := 'X';             -- hps_io_usb1_inst_D6
			hps_io_hps_io_usb1_inst_D7             : inout std_logic                     := 'X';             -- hps_io_usb1_inst_D7
			hps_io_hps_io_usb1_inst_CLK            : in    std_logic                     := 'X';             -- hps_io_usb1_inst_CLK
			hps_io_hps_io_usb1_inst_STP            : out   std_logic;                                        -- hps_io_usb1_inst_STP
			hps_io_hps_io_usb1_inst_DIR            : in    std_logic                     := 'X';             -- hps_io_usb1_inst_DIR
			hps_io_hps_io_usb1_inst_NXT            : in    std_logic                     := 'X';             -- hps_io_usb1_inst_NXT
			hps_io_hps_io_spim0_inst_CLK           : out   std_logic;                                        -- hps_io_spim0_inst_CLK
			hps_io_hps_io_spim0_inst_MOSI          : out   std_logic;                                        -- hps_io_spim0_inst_MOSI
			hps_io_hps_io_spim0_inst_MISO          : in    std_logic                     := 'X';             -- hps_io_spim0_inst_MISO
			hps_io_hps_io_spim0_inst_SS0           : out   std_logic;                                        -- hps_io_spim0_inst_SS0
			hps_io_hps_io_uart0_inst_RX            : in    std_logic                     := 'X';             -- hps_io_uart0_inst_RX
			hps_io_hps_io_uart0_inst_TX            : out   std_logic;                                        -- hps_io_uart0_inst_TX
			hps_io_hps_io_uart1_inst_RX            : in    std_logic                     := 'X';             -- hps_io_uart1_inst_RX
			hps_io_hps_io_uart1_inst_TX            : out   std_logic;                                        -- hps_io_uart1_inst_TX
			hps_io_hps_io_i2c0_inst_SDA            : inout std_logic                     := 'X';             -- hps_io_i2c0_inst_SDA
			hps_io_hps_io_i2c0_inst_SCL            : inout std_logic                     := 'X';             -- hps_io_i2c0_inst_SCL
			hps_io_hps_io_i2c1_inst_SDA            : inout std_logic                     := 'X';             -- hps_io_i2c1_inst_SDA
			hps_io_hps_io_i2c1_inst_SCL            : inout std_logic                     := 'X';             -- hps_io_i2c1_inst_SCL
			hps_io_hps_io_can1_inst_RX             : in    std_logic                     := 'X';             -- hps_io_can1_inst_RX
			hps_io_hps_io_can1_inst_TX             : out   std_logic;                                        -- hps_io_can1_inst_TX
			hps_io_hps_io_gpio_inst_GPIO40         : inout std_logic                     := 'X';             -- hps_io_gpio_inst_GPIO40
			hps_io_hps_io_gpio_inst_GPIO41         : inout std_logic                     := 'X';             -- hps_io_gpio_inst_GPIO41
			hps_io_hps_io_gpio_inst_GPIO42         : inout std_logic                     := 'X';             -- hps_io_gpio_inst_GPIO42
			hps_io_hps_io_gpio_inst_GPIO43         : inout std_logic                     := 'X';             -- hps_io_gpio_inst_GPIO43
			hps_io_hps_io_gpio_inst_GPIO44         : inout std_logic                     := 'X';             -- hps_io_gpio_inst_GPIO44
			hps_io_hps_io_gpio_inst_GPIO48         : inout std_logic                     := 'X';             -- hps_io_gpio_inst_GPIO48
			hps_io_hps_io_gpio_inst_GPIO65         : inout std_logic                     := 'X';             -- hps_io_gpio_inst_GPIO65
			memory_mem_a                           : out   std_logic_vector(9 downto 0);                     -- mem_a
			memory_mem_ck                          : out   std_logic;                                        -- mem_ck
			memory_mem_ck_n                        : out   std_logic;                                        -- mem_ck_n
			memory_mem_cke                         : out   std_logic;                                        -- mem_cke
			memory_mem_cs_n                        : out   std_logic;                                        -- mem_cs_n
			memory_mem_dq                          : inout std_logic_vector(31 downto 0) := (others => 'X'); -- mem_dq
			memory_mem_dqs                         : inout std_logic_vector(3 downto 0)  := (others => 'X'); -- mem_dqs
			memory_mem_dqs_n                       : inout std_logic_vector(3 downto 0)  := (others => 'X'); -- mem_dqs_n
			memory_mem_dm                          : out   std_logic_vector(3 downto 0);                     -- mem_dm
			memory_oct_rzqin                       : in    std_logic                     := 'X';             -- oct_rzqin
			reset_reset_n                          : in    std_logic                     := 'X';             -- reset_n
			slide_sw_external_connection_export    : in    std_logic_vector(3 downto 0)  := (others => 'X'); -- export
			fpga_sensor_external_connection_export : in    std_logic_vector(3 downto 0)  := (others => 'X')  -- export
		);
	end component simple_system;

	u0 : component simple_system
		port map (
			clk_clk                                => CONNECTED_TO_clk_clk,                                --                             clk.clk
			fpga_key_external_connection_export    => CONNECTED_TO_fpga_key_external_connection_export,    --    fpga_key_external_connection.export
			fpga_led_external_connection_export    => CONNECTED_TO_fpga_led_external_connection_export,    --    fpga_led_external_connection.export
			hps_io_hps_io_emac1_inst_TX_CLK        => CONNECTED_TO_hps_io_hps_io_emac1_inst_TX_CLK,        --                          hps_io.hps_io_emac1_inst_TX_CLK
			hps_io_hps_io_emac1_inst_TXD0          => CONNECTED_TO_hps_io_hps_io_emac1_inst_TXD0,          --                                .hps_io_emac1_inst_TXD0
			hps_io_hps_io_emac1_inst_TXD1          => CONNECTED_TO_hps_io_hps_io_emac1_inst_TXD1,          --                                .hps_io_emac1_inst_TXD1
			hps_io_hps_io_emac1_inst_TXD2          => CONNECTED_TO_hps_io_hps_io_emac1_inst_TXD2,          --                                .hps_io_emac1_inst_TXD2
			hps_io_hps_io_emac1_inst_TXD3          => CONNECTED_TO_hps_io_hps_io_emac1_inst_TXD3,          --                                .hps_io_emac1_inst_TXD3
			hps_io_hps_io_emac1_inst_RXD0          => CONNECTED_TO_hps_io_hps_io_emac1_inst_RXD0,          --                                .hps_io_emac1_inst_RXD0
			hps_io_hps_io_emac1_inst_MDIO          => CONNECTED_TO_hps_io_hps_io_emac1_inst_MDIO,          --                                .hps_io_emac1_inst_MDIO
			hps_io_hps_io_emac1_inst_MDC           => CONNECTED_TO_hps_io_hps_io_emac1_inst_MDC,           --                                .hps_io_emac1_inst_MDC
			hps_io_hps_io_emac1_inst_RX_CTL        => CONNECTED_TO_hps_io_hps_io_emac1_inst_RX_CTL,        --                                .hps_io_emac1_inst_RX_CTL
			hps_io_hps_io_emac1_inst_TX_CTL        => CONNECTED_TO_hps_io_hps_io_emac1_inst_TX_CTL,        --                                .hps_io_emac1_inst_TX_CTL
			hps_io_hps_io_emac1_inst_RX_CLK        => CONNECTED_TO_hps_io_hps_io_emac1_inst_RX_CLK,        --                                .hps_io_emac1_inst_RX_CLK
			hps_io_hps_io_emac1_inst_RXD1          => CONNECTED_TO_hps_io_hps_io_emac1_inst_RXD1,          --                                .hps_io_emac1_inst_RXD1
			hps_io_hps_io_emac1_inst_RXD2          => CONNECTED_TO_hps_io_hps_io_emac1_inst_RXD2,          --                                .hps_io_emac1_inst_RXD2
			hps_io_hps_io_emac1_inst_RXD3          => CONNECTED_TO_hps_io_hps_io_emac1_inst_RXD3,          --                                .hps_io_emac1_inst_RXD3
			hps_io_hps_io_qspi_inst_IO0            => CONNECTED_TO_hps_io_hps_io_qspi_inst_IO0,            --                                .hps_io_qspi_inst_IO0
			hps_io_hps_io_qspi_inst_IO1            => CONNECTED_TO_hps_io_hps_io_qspi_inst_IO1,            --                                .hps_io_qspi_inst_IO1
			hps_io_hps_io_qspi_inst_IO2            => CONNECTED_TO_hps_io_hps_io_qspi_inst_IO2,            --                                .hps_io_qspi_inst_IO2
			hps_io_hps_io_qspi_inst_IO3            => CONNECTED_TO_hps_io_hps_io_qspi_inst_IO3,            --                                .hps_io_qspi_inst_IO3
			hps_io_hps_io_qspi_inst_SS0            => CONNECTED_TO_hps_io_hps_io_qspi_inst_SS0,            --                                .hps_io_qspi_inst_SS0
			hps_io_hps_io_qspi_inst_CLK            => CONNECTED_TO_hps_io_hps_io_qspi_inst_CLK,            --                                .hps_io_qspi_inst_CLK
			hps_io_hps_io_sdio_inst_CMD            => CONNECTED_TO_hps_io_hps_io_sdio_inst_CMD,            --                                .hps_io_sdio_inst_CMD
			hps_io_hps_io_sdio_inst_D0             => CONNECTED_TO_hps_io_hps_io_sdio_inst_D0,             --                                .hps_io_sdio_inst_D0
			hps_io_hps_io_sdio_inst_D1             => CONNECTED_TO_hps_io_hps_io_sdio_inst_D1,             --                                .hps_io_sdio_inst_D1
			hps_io_hps_io_sdio_inst_CLK            => CONNECTED_TO_hps_io_hps_io_sdio_inst_CLK,            --                                .hps_io_sdio_inst_CLK
			hps_io_hps_io_sdio_inst_D2             => CONNECTED_TO_hps_io_hps_io_sdio_inst_D2,             --                                .hps_io_sdio_inst_D2
			hps_io_hps_io_sdio_inst_D3             => CONNECTED_TO_hps_io_hps_io_sdio_inst_D3,             --                                .hps_io_sdio_inst_D3
			hps_io_hps_io_usb1_inst_D0             => CONNECTED_TO_hps_io_hps_io_usb1_inst_D0,             --                                .hps_io_usb1_inst_D0
			hps_io_hps_io_usb1_inst_D1             => CONNECTED_TO_hps_io_hps_io_usb1_inst_D1,             --                                .hps_io_usb1_inst_D1
			hps_io_hps_io_usb1_inst_D2             => CONNECTED_TO_hps_io_hps_io_usb1_inst_D2,             --                                .hps_io_usb1_inst_D2
			hps_io_hps_io_usb1_inst_D3             => CONNECTED_TO_hps_io_hps_io_usb1_inst_D3,             --                                .hps_io_usb1_inst_D3
			hps_io_hps_io_usb1_inst_D4             => CONNECTED_TO_hps_io_hps_io_usb1_inst_D4,             --                                .hps_io_usb1_inst_D4
			hps_io_hps_io_usb1_inst_D5             => CONNECTED_TO_hps_io_hps_io_usb1_inst_D5,             --                                .hps_io_usb1_inst_D5
			hps_io_hps_io_usb1_inst_D6             => CONNECTED_TO_hps_io_hps_io_usb1_inst_D6,             --                                .hps_io_usb1_inst_D6
			hps_io_hps_io_usb1_inst_D7             => CONNECTED_TO_hps_io_hps_io_usb1_inst_D7,             --                                .hps_io_usb1_inst_D7
			hps_io_hps_io_usb1_inst_CLK            => CONNECTED_TO_hps_io_hps_io_usb1_inst_CLK,            --                                .hps_io_usb1_inst_CLK
			hps_io_hps_io_usb1_inst_STP            => CONNECTED_TO_hps_io_hps_io_usb1_inst_STP,            --                                .hps_io_usb1_inst_STP
			hps_io_hps_io_usb1_inst_DIR            => CONNECTED_TO_hps_io_hps_io_usb1_inst_DIR,            --                                .hps_io_usb1_inst_DIR
			hps_io_hps_io_usb1_inst_NXT            => CONNECTED_TO_hps_io_hps_io_usb1_inst_NXT,            --                                .hps_io_usb1_inst_NXT
			hps_io_hps_io_spim0_inst_CLK           => CONNECTED_TO_hps_io_hps_io_spim0_inst_CLK,           --                                .hps_io_spim0_inst_CLK
			hps_io_hps_io_spim0_inst_MOSI          => CONNECTED_TO_hps_io_hps_io_spim0_inst_MOSI,          --                                .hps_io_spim0_inst_MOSI
			hps_io_hps_io_spim0_inst_MISO          => CONNECTED_TO_hps_io_hps_io_spim0_inst_MISO,          --                                .hps_io_spim0_inst_MISO
			hps_io_hps_io_spim0_inst_SS0           => CONNECTED_TO_hps_io_hps_io_spim0_inst_SS0,           --                                .hps_io_spim0_inst_SS0
			hps_io_hps_io_uart0_inst_RX            => CONNECTED_TO_hps_io_hps_io_uart0_inst_RX,            --                                .hps_io_uart0_inst_RX
			hps_io_hps_io_uart0_inst_TX            => CONNECTED_TO_hps_io_hps_io_uart0_inst_TX,            --                                .hps_io_uart0_inst_TX
			hps_io_hps_io_uart1_inst_RX            => CONNECTED_TO_hps_io_hps_io_uart1_inst_RX,            --                                .hps_io_uart1_inst_RX
			hps_io_hps_io_uart1_inst_TX            => CONNECTED_TO_hps_io_hps_io_uart1_inst_TX,            --                                .hps_io_uart1_inst_TX
			hps_io_hps_io_i2c0_inst_SDA            => CONNECTED_TO_hps_io_hps_io_i2c0_inst_SDA,            --                                .hps_io_i2c0_inst_SDA
			hps_io_hps_io_i2c0_inst_SCL            => CONNECTED_TO_hps_io_hps_io_i2c0_inst_SCL,            --                                .hps_io_i2c0_inst_SCL
			hps_io_hps_io_i2c1_inst_SDA            => CONNECTED_TO_hps_io_hps_io_i2c1_inst_SDA,            --                                .hps_io_i2c1_inst_SDA
			hps_io_hps_io_i2c1_inst_SCL            => CONNECTED_TO_hps_io_hps_io_i2c1_inst_SCL,            --                                .hps_io_i2c1_inst_SCL
			hps_io_hps_io_can1_inst_RX             => CONNECTED_TO_hps_io_hps_io_can1_inst_RX,             --                                .hps_io_can1_inst_RX
			hps_io_hps_io_can1_inst_TX             => CONNECTED_TO_hps_io_hps_io_can1_inst_TX,             --                                .hps_io_can1_inst_TX
			hps_io_hps_io_gpio_inst_GPIO40         => CONNECTED_TO_hps_io_hps_io_gpio_inst_GPIO40,         --                                .hps_io_gpio_inst_GPIO40
			hps_io_hps_io_gpio_inst_GPIO41         => CONNECTED_TO_hps_io_hps_io_gpio_inst_GPIO41,         --                                .hps_io_gpio_inst_GPIO41
			hps_io_hps_io_gpio_inst_GPIO42         => CONNECTED_TO_hps_io_hps_io_gpio_inst_GPIO42,         --                                .hps_io_gpio_inst_GPIO42
			hps_io_hps_io_gpio_inst_GPIO43         => CONNECTED_TO_hps_io_hps_io_gpio_inst_GPIO43,         --                                .hps_io_gpio_inst_GPIO43
			hps_io_hps_io_gpio_inst_GPIO44         => CONNECTED_TO_hps_io_hps_io_gpio_inst_GPIO44,         --                                .hps_io_gpio_inst_GPIO44
			hps_io_hps_io_gpio_inst_GPIO48         => CONNECTED_TO_hps_io_hps_io_gpio_inst_GPIO48,         --                                .hps_io_gpio_inst_GPIO48
			hps_io_hps_io_gpio_inst_GPIO65         => CONNECTED_TO_hps_io_hps_io_gpio_inst_GPIO65,         --                                .hps_io_gpio_inst_GPIO65
			memory_mem_a                           => CONNECTED_TO_memory_mem_a,                           --                          memory.mem_a
			memory_mem_ck                          => CONNECTED_TO_memory_mem_ck,                          --                                .mem_ck
			memory_mem_ck_n                        => CONNECTED_TO_memory_mem_ck_n,                        --                                .mem_ck_n
			memory_mem_cke                         => CONNECTED_TO_memory_mem_cke,                         --                                .mem_cke
			memory_mem_cs_n                        => CONNECTED_TO_memory_mem_cs_n,                        --                                .mem_cs_n
			memory_mem_dq                          => CONNECTED_TO_memory_mem_dq,                          --                                .mem_dq
			memory_mem_dqs                         => CONNECTED_TO_memory_mem_dqs,                         --                                .mem_dqs
			memory_mem_dqs_n                       => CONNECTED_TO_memory_mem_dqs_n,                       --                                .mem_dqs_n
			memory_mem_dm                          => CONNECTED_TO_memory_mem_dm,                          --                                .mem_dm
			memory_oct_rzqin                       => CONNECTED_TO_memory_oct_rzqin,                       --                                .oct_rzqin
			reset_reset_n                          => CONNECTED_TO_reset_reset_n,                          --                           reset.reset_n
			slide_sw_external_connection_export    => CONNECTED_TO_slide_sw_external_connection_export,    --    slide_sw_external_connection.export
			fpga_sensor_external_connection_export => CONNECTED_TO_fpga_sensor_external_connection_export  -- fpga_sensor_external_connection.export
		);

