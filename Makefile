all: redpitaya_eng.pdf

redpitaya_eng.pdf: redpitaya_eng.tex fpga_manager_zynq_eng.tex
	pdflatex redpitaya_eng.tex

clean:
	rm redpitaya_eng.aux redpitaya_eng.log redpitaya_eng.pdf
