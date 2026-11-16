import ssl
from pyVim.connect import SmartConnect, Disconnect
from pyVmomi import vim

ctx = ssl._create_unverified_context()
si = None

try:
    si = SmartConnect(
        host="127.0.0.1",
        user="administrator@domain.ad",
        pwd="******",
        sslContext=ctx,
    )

    content = si.RetrieveContent()
    view = content.viewManager.CreateContainerView(
        content.rootFolder, [vim.VirtualMachine], True
    )

    try:
        for vm in view.view:
            ip = vm.guest.ipAddress or "N/A"

            if ip == "N/A":
                for net in (vm.guest.net or []):
                    addresses = net.ipConfig.ipAddress if net.ipConfig else []
                    if addresses:
                        ip = addresses[0].ipAddress
                        break

            print(
                f"VM: {vm.name}\n"
                f"Power: {vm.runtime.powerState}\n"
                f"OS: {vm.config.guestFullName}\n"
                f"Tools: {vm.guest.toolsStatus}\n"
                f"IP: {ip}\n"
                f"Notes: {vm.config.annotation}\n"
            )
    finally:
        view.Destroy()

finally:
    if si is not None:
        Disconnect(si)

