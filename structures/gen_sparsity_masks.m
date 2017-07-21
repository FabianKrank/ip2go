function [ custom_structures ] = gen_sparsity_masks( matrix_structures, mem_type, simple_struct )
%gen_sparsity_masks Defines sparsity masks from matrix_structures
custom_structures = cell(0);
if (simple_struct==1 )&& (mem_type==2)
    % Gütefunktion - quad
    custom_structures{end+1} = structures_gen_custom('Hxx_0',matrix_structures.Hxx{1});
    custom_structures{end+1} = structures_gen_custom('Hxu_0',matrix_structures.Hxu{1});
    custom_structures{end+1} = structures_gen_custom('Huu_0',matrix_structures.Huu{1});
    custom_structures{end+1} = structures_gen_custom('Hss_0',matrix_structures.Hss{1});
    % Gütefunktion - lin
    custom_structures{end+1} = structures_gen_custom('f0x_0',matrix_structures.f0x{1});
    custom_structures{end+1} = structures_gen_custom('f0u_0',matrix_structures.f0u{1});
    custom_structures{end+1} = structures_gen_custom('f0s_0',matrix_structures.f0s{1});
    % GNBs
    custom_structures{end+1} = structures_gen_custom('fx_0',matrix_structures.fx{1});
    custom_structures{end+1} = structures_gen_custom('fu_0',matrix_structures.fu{1});
    custom_structures{end+1} = structures_gen_custom('f_0',matrix_structures.f{1});
    % UGNBs
    custom_structures{end+1} = structures_gen_custom('gx_0',matrix_structures.gx{1});
    custom_structures{end+1} = structures_gen_custom('gu_0',matrix_structures.gu{1});
    custom_structures{end+1} = structures_gen_custom('g_0',matrix_structures.g{1});
elseif (simple_struct==1 )&& (mem_type==1)
    custom_structures{end+1} = structures_gen_custom('Hxx_0',matrix_structures.Hxx{1});
    custom_structures{end+1} = structures_gen_custom('Hxx_k',matrix_structures.Hxx{1});
    custom_structures{end+1} = structures_gen_custom('Hxx_end',matrix_structures.Hxx{1});
    custom_structures{end+1} = structures_gen_custom('Hxu_0',matrix_structures.Hxu{1});
    custom_structures{end+1} = structures_gen_custom('Hxu_k',matrix_structures.Hxu{1});
    custom_structures{end+1} = structures_gen_custom('Hxu_end',matrix_structures.Hxu{1});
    custom_structures{end+1} = structures_gen_custom('Huu_0',matrix_structures.Huu{1});
    custom_structures{end+1} = structures_gen_custom('Huu_k',matrix_structures.Huu{1});
    custom_structures{end+1} = structures_gen_custom('Huu_end',matrix_structures.Huu{1});
    custom_structures{end+1} = structures_gen_custom('Hss_0',matrix_structures.Hss{1});
    custom_structures{end+1} = structures_gen_custom('Hss_k',matrix_structures.Hss{1});
    custom_structures{end+1} = structures_gen_custom('Hss_end',matrix_structures.Hss{1});
    % Gütefunktion - lin
    custom_structures{end+1} = structures_gen_custom('f0x_0',matrix_structures.f0x{1});
    custom_structures{end+1} = structures_gen_custom('f0x_k',matrix_structures.f0x{1});
    custom_structures{end+1} = structures_gen_custom('f0x_end',matrix_structures.f0x{1});
    custom_structures{end+1} = structures_gen_custom('f0u_0',matrix_structures.f0u{1});
    custom_structures{end+1} = structures_gen_custom('f0u_k',matrix_structures.f0u{1});
    custom_structures{end+1} = structures_gen_custom('f0u_end',matrix_structures.f0u{1});
    custom_structures{end+1} = structures_gen_custom('f0s_0',matrix_structures.f0s{1});
    custom_structures{end+1} = structures_gen_custom('f0s_k',matrix_structures.f0s{1});
    custom_structures{end+1} = structures_gen_custom('f0s_end',matrix_structures.f0s{1});
    % GNBs
    custom_structures{end+1} = structures_gen_custom('fx_0',matrix_structures.fx{1});
    custom_structures{end+1} = structures_gen_custom('fx_k',matrix_structures.fx{1});
    custom_structures{end+1} = structures_gen_custom('fx_end',matrix_structures.fx{1});
    custom_structures{end+1} = structures_gen_custom('fu_0',matrix_structures.fu{1});
    custom_structures{end+1} = structures_gen_custom('fu_k',matrix_structures.fu{1});
    custom_structures{end+1} = structures_gen_custom('fu_end',matrix_structures.fu{1});
    custom_structures{end+1} = structures_gen_custom('f_0',matrix_structures.f{1});
    custom_structures{end+1} = structures_gen_custom('f_k',matrix_structures.f{1});
    custom_structures{end+1} = structures_gen_custom('f_end',matrix_structures.f{1});
    % UGNBs
    custom_structures{end+1} = structures_gen_custom('gx_0',matrix_structures.gx{1});
    custom_structures{end+1} = structures_gen_custom('gx_k',matrix_structures.gx{1});
    custom_structures{end+1} = structures_gen_custom('gx_end',matrix_structures.gx{1});
    custom_structures{end+1} = structures_gen_custom('gu_0',matrix_structures.gu{1});
    custom_structures{end+1} = structures_gen_custom('gu_k',matrix_structures.gu{1});
    custom_structures{end+1} = structures_gen_custom('gu_end',matrix_structures.gu{1});
    custom_structures{end+1} = structures_gen_custom('g_0',matrix_structures.g{1});
    custom_structures{end+1} = structures_gen_custom('g_k',matrix_structures.g{1});
    custom_structures{end+1} = structures_gen_custom('g_end',matrix_structures.g{1});
else    % Gütefunktion - quad
    custom_structures{end+1} = structures_gen_custom('Hxx_0',matrix_structures.Hxx{1});
    custom_structures{end+1} = structures_gen_custom('Hxx_k',matrix_structures.Hxx{2});
    custom_structures{end+1} = structures_gen_custom('Hxx_end',matrix_structures.Hxx{end});
    custom_structures{end+1} = structures_gen_custom('Hxu_0',matrix_structures.Hxu{1});
    custom_structures{end+1} = structures_gen_custom('Hxu_k',matrix_structures.Hxu{2});
    custom_structures{end+1} = structures_gen_custom('Hxu_end',matrix_structures.Hxu{end});
    custom_structures{end+1} = structures_gen_custom('Huu_0',matrix_structures.Huu{1});
    custom_structures{end+1} = structures_gen_custom('Huu_k',matrix_structures.Huu{2});
    custom_structures{end+1} = structures_gen_custom('Huu_end',matrix_structures.Huu{end});
    custom_structures{end+1} = structures_gen_custom('Hss_0',matrix_structures.Hss{1});
    custom_structures{end+1} = structures_gen_custom('Hss_k',matrix_structures.Hss{2});
    custom_structures{end+1} = structures_gen_custom('Hss_end',matrix_structures.Hss{end});
    % Gütefunktion - lin
    custom_structures{end+1} = structures_gen_custom('f0x_0',matrix_structures.f0x{1});
    custom_structures{end+1} = structures_gen_custom('f0x_k',matrix_structures.f0x{2});
    custom_structures{end+1} = structures_gen_custom('f0x_end',matrix_structures.f0x{end});
    custom_structures{end+1} = structures_gen_custom('f0u_0',matrix_structures.f0u{1});
    custom_structures{end+1} = structures_gen_custom('f0u_k',matrix_structures.f0u{2});
    custom_structures{end+1} = structures_gen_custom('f0u_end',matrix_structures.f0u{end});
    custom_structures{end+1} = structures_gen_custom('f0s_0',matrix_structures.f0s{1});
    custom_structures{end+1} = structures_gen_custom('f0s_k',matrix_structures.f0s{2});
    custom_structures{end+1} = structures_gen_custom('f0s_end',matrix_structures.f0s{end});
    % GNBs
    custom_structures{end+1} = structures_gen_custom('fx_0',matrix_structures.fx{1});
    custom_structures{end+1} = structures_gen_custom('fx_k',matrix_structures.fx{2});
    custom_structures{end+1} = structures_gen_custom('fx_end',matrix_structures.fx{end});
    custom_structures{end+1} = structures_gen_custom('fu_0',matrix_structures.fu{1});
    custom_structures{end+1} = structures_gen_custom('fu_k',matrix_structures.fu{2});
    custom_structures{end+1} = structures_gen_custom('fu_end',matrix_structures.fu{end});
    custom_structures{end+1} = structures_gen_custom('f_0',matrix_structures.f{1});
    custom_structures{end+1} = structures_gen_custom('f_k',matrix_structures.f{2});
    custom_structures{end+1} = structures_gen_custom('f_end',matrix_structures.f{end});
    % UGNBs
    custom_structures{end+1} = structures_gen_custom('gx_0',matrix_structures.gx{1});
    custom_structures{end+1} = structures_gen_custom('gx_k',matrix_structures.gx{2});
    custom_structures{end+1} = structures_gen_custom('gx_end',matrix_structures.gx{end});
    custom_structures{end+1} = structures_gen_custom('gu_0',matrix_structures.gu{1});
    custom_structures{end+1} = structures_gen_custom('gu_k',matrix_structures.gu{2});
    custom_structures{end+1} = structures_gen_custom('gu_end',matrix_structures.gu{end});
    custom_structures{end+1} = structures_gen_custom('g_0',matrix_structures.g{1});
    custom_structures{end+1} = structures_gen_custom('g_k',matrix_structures.g{2});
    custom_structures{end+1} = structures_gen_custom('g_end',matrix_structures.g{end});
end

end

