`include "def.v"
`ifdef SIM
`include "ram_uart.v"
`include "cpu_uart.v"
`endif

module testbench;
reg clk, rst;
wire Rx, Tx;
wire[15:0] led;
wire[10:0] disp;
riscv_cpu cpu(clk, rst, Rx, Tx, disp, led);
ram_uart mem(clk, rst, Rx, Tx);
initial begin
    $dumpfile("test.vcd");
    $dumpvars(0,cpu);
    $dumpvars(0,mem);
    rst = 0;
    clk = 0;
    rst = 1;
    repeat(100) #1 clk=!clk;
    rst = 0;
    //repeat(10000) #1 clk=!clk;
    forever #1 clk=!clk;
    //#50000;
    //////$display("CPU TIMEOUT");
    //$finish;
end
endmodule