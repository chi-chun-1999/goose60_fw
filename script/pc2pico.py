import hid

def send_hid_report(dev, report_id, btn):
    # Create a report with the report ID and button state
    report = [0] * 3  # Report ID + 2 bytes for button state
    report[0] = report_id
    report[1] = btn & 0xFF
    report[2] = (btn >> 8) & 0xFF

    # Send the report to the device
    dev.write(report)
    print(f"Sent report: {report}")


VID = 0xCafe
PID = 0x4000


dev = hid.device()

dev.open(51966, PID)
# print("Device opened", dev.get_product_string())

# send 64 bytes (must match report size)
# Restart command 
data_out = bytes([0xA0]+[0xFF]+[0xFF])
dev.write(data_out)

# Send reports with different button states
# send_hid_report(dev, 2, 1)  # Button 1 pressed


dev.close()
