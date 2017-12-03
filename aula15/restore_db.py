CAD_PESSOAS = \
"""0001|0021|1|Cristina Souza|Tecnica Administrativa|Rua AA, 154|Secretaria|Pleno|05|0|1|
0002|0042|1|Haroldo Teles|Tecnico Eletronico|Rua BB, 32|Suporte|Junior|03|1|1|
0003|0000|2|Carlos Peixoto|Engenheiro Eletrico|Alameda ZZ, 187|Engenheiro|Senior|07|0|0|
0004|0063|1|Teresa Alves|Engenheiro de Producao|Rua CCC, 501|Engenheiro|Senior|06|1|2|
0005|0000|2|Eliana Silva|Administrador de Empresa|Rua DD, 735|Administrador|Diretor|09|0|0|
0006|0000|2|Ricardo Souza Carvalho|Contador|Praca E, 128|Contador|Pleno|04|0|0|
"""

HORAS_AUTO = \
"""0063|168|
"""

TAB_CS = \
"""Administrador|2.0|
Contador|1.5|
Engenheiro|1.5|
Entregador|0.5|
Estudante|0.0|
Secretaria|1.0|
Suporte|0.5|
"""

TAB_IR = \
"""0.01|1200.00|0.0|0.00|
1200.01|2200.00|15.0|180.00|
2200.01|99999.99|25.0|480.00|
"""

TAB_SAL = \
"""01|390.00|
02|460.00|
03|800.00|
04|1400.00|
05|2300.00|
06|2850.00|
07|4600.00|
08|6000.00|
09|9000.00|
"""

TAB_VAL_HORA = \
"""01|2.26|
02|2.68|
03|4.76|
04|7.74|
05|13.10|
06|16.67|
07|26.79|
08|35.71|
09|53.57|
"""

with open("cadpessoas.dat", "w") as text_file:
    text_file.write("%s" % CAD_PESSOAS)

with open("horasauto.dat", "w") as text_file:
    text_file.write("%s" % HORAS_AUTO)

with open("tabcs.dat", "w") as text_file:
    text_file.write("%s" % TAB_CS)

with open("tabir.dat", "w") as text_file:
    text_file.write("%s" % TAB_IR)

with open("tabsalarial.dat", "w") as text_file:
    text_file.write("%s" % TAB_SAL)

with open("tabvalorhora.dat", "w") as text_file:
    text_file.write("%s" % TAB_VAL_HORA)
