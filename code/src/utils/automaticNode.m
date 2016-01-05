%Calculate the positions
pos =0:0.1:1;
%Actual writing the nodes
fileID = fopen('nodes.txt','w');
for i=1:length(pos)
test = num2str(pos(i));
translation = strcat(['  translation 0 0 ',test]);
    
fprintf(fileID,'%s \n','DEF ICECRUST Solid {');
fprintf(fileID,'%s \n',translation);
fprintf(fileID,'%s \n','  children [');
fprintf(fileID,'%s \n','    DEF ICE_BOX Shape {');
fprintf(fileID,'%s \n','      appearance Appearance {');
fprintf(fileID,'%s \n','         material Material {');
fprintf(fileID,'%s \n','           diffuseColor 0 0.498039 1');
fprintf(fileID,'%s \n','         }');
fprintf(fileID,'%s \n','         texture ImageTexture {');
fprintf(fileID,'%s \n','           url [');
fprintf(fileID,'%s \n','             "Europa_Ice_Rafts.jpg"');
fprintf(fileID,'%s \n','           ]');
fprintf(fileID,'%s \n','         }');
fprintf(fileID,'%s \n','       }');
fprintf(fileID,'%s \n','       geometry Box {');
fprintf(fileID,'%s \n','        size 0.1 0.1 0.1');
fprintf(fileID,'%s \n','      }');
fprintf(fileID,'%s \n','    }');
fprintf(fileID,'%s \n','  ]');
fprintf(fileID,'%s \n','  boundingObject USE ICE_BOX');
fprintf(fileID,'%s \n','}');
end
fclose(fileID);
%Node Text:
% DEF ICECRUST Solid {
%   translation 0 0 0.1
%   children [
%     DEF ICE_BOX Shape {
%       appearance Appearance {
%         material Material {
%           diffuseColor 0 0.498039 1
%         }
%         texture ImageTexture {
%           url [
%             "Europa_Ice_Rafts.jpg"
%           ]
%         }
%       }
%       geometry Box {
%         size 0.1 0.1 0.1
%       }
%     }
%   ]
%   boundingObject USE ICE_BOX
% }