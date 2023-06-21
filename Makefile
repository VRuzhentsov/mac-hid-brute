deploy-ps-uf2:
	@echo "Deploying firmware.uf2 to E: drive"
	@powershell -Command "Copy-Item -Path .pio/build/rpipicow/firmware.uf2 -Destination E:"