building software

Quartus:
	build qsys
	compile quartus

software:
	run shell script
		sh create_preloader_dir.sh
	build preloader
		make -C software/preloader
	build uboot
		make -C software/preloader uboot

